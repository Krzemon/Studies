%% Podstawy kompresji JPEG
clear; clc; close all;

%% Parametry kompresji
quality = 65;        % Współczynnik jakości po kompresji [%] (zakres 1 - 100 )

%% Ładowanie i wyświetlanie zdjęcia
image = double( rgb2gray( imread( 'media/village.jpg' ) ) );

f = figure; ax = axes(f); 
imshow( image, [], 'Parent', ax );
title( ax, "Oryginalne zdjęcie");


%% Krok 1 - kowersja RGB do YUV
% Pomijana gdy obraz jest w skali szarości.
% Konwertujemy obraz do skali szarości ładując go, własnie aby ominąć ten
% krok (przestrzenie barw są poza zakresem przedmiotu)

%% Krok 2 - przygotowanie do podziału obrazu na bloki 8x8
[ height, width ] = size( image );

% Jeżeli rozmiar (wysokość, szerokość) obrazu nie jest wielokrotnością 8,
% obraz należy uzupełnić zerami.
height8 = mod( height, 8 );
if height8 > 0
    height8 = 8 - height8;
end

width8 = mod( width, 8 );
if width8 > 0
    width8 = 8 - width8;
end

image( ( height+1 ):( height + height8 ), : ) = zeros( height8, width );
image( :, ( width+1 ):( width + width8 ) ) = zeros( height + height8, width8 );


%% Krok 3 - Obliczenie DCT dla każdego z bloków 8x8

blockDctFun = @(block_struct) dct2( block_struct.data );
dctImage = blockproc( image, [ 8, 8 ], blockDctFun );

%% Widmo bloków
f = figure; ax = axes(f); 
imshow( mat2gray( log( 1 + abs( dctImage ) ) ), 'Parent', ax );
title( ax, "Widmo DCT");

%% Krok 4 - Wyznaczenie macierzy kwantyzacji dla zadanej jakości
% https://stackoverflow.com/questions/29215879/how-can-i-generalize-the-quantization-matrix-in-jpeg-compression

QuantLuminance = [ 
    16    11    10    16    24    40    51    61;
    12    12    14    19    26    58    60    55;
    14    13    16    24    40    57    69    56;
    14    17    22    29    51    87    80    62;
    18    22    37    56    68   109   103    77;
    24    35    55    64    81   104   113    92;
    49    64    78    87   103   121   120   101;
    72    92    95    98   112   100   103    99;
];

if quality < 50
    S = 5000 / quality;
else
    S = 200 - 2*quality;
end

QuantLuminanceScaled = floor( ( S * QuantLuminance + 50 ) / 100 );

QuantLuminanceScaled( QuantLuminanceScaled == 0 ) = 1; % Aby zapobiec dzieleniu przez zero

%% Krok 4 - Kwantyzacja współczynników transformaty kosinusowej

dctQuantFun = @(block_struct) round( block_struct.data ./ QuantLuminanceScaled );
dctQuantImage = blockproc( dctImage, [ 8, 8 ], dctQuantFun );

%% Krok 5 - Tutaj powinna nastąpić kompresja bezstratna
% 1. Zamiana tablicy współczynników na wektor
% 2. Kodowanie "Run-length encoding (RLE)" - zamiana ciągów zer na jedną
%    (prawie...) liczbę reprezentującją ilość zer w ciągu
% 3. Kodowanie entropijne z użyciem kodu Huffmana
% Kompresję bezstratną pomijamy - jest poza zakresem przedmiotu.

%% Obraz po kompresji JPEG
f = figure; ax = axes(f); 
imshow( mat2gray( log( 1 + abs( dctQuantImage ) ) ), 'Parent', ax );
title( ax, "Skompresowane widmo DCT");

%% Dekoder JPEG

% Krok 1 - pomijamy (dekompresja bezstratna)

%% Krok 2 - Odwrócenie kwantyzacji - możenie przez macierz

dctUnquantFun =  @(block_struct) round( block_struct.data .* QuantLuminanceScaled );
dctUnquantImage = blockproc( dctQuantImage, [ 8, 8 ], dctUnquantFun );

%% Krok 3 - Obliczenie transformaty odwrotnej

blockIdctFun = @(block_struct) idct2( block_struct.data );
compressedImage = blockproc( dctUnquantImage, [ 8, 8 ], blockIdctFun );

f = figure; ax = axes(f); 
imshow( compressedImage, [], 'Parent', ax );
title( ax, "Skompresowane zdjęcie");

%% Obliczenie stopnia kompresji
noOfPixels = width * height;
noOfDctCoefs = sum( dctImage( : ) ~= 0 );
noOfCompressCoefs  = sum( dctQuantImage( : ) ~= 0 );

dctCompressionRate = 100 * noOfDctCoefs / noOfPixels;
jpegCompressionRate = 100 * noOfCompressCoefs / noOfPixels;

fprintf( "Ilość pikseli w zdjęciu                       = %d\n", noOfPixels );
fprintf( "Ilość niezerowych współczynników DCT          = %d\n", noOfDctCoefs );
fprintf( "Ilość niezerowych współczynników po kompresji = %d\n\n", noOfCompressCoefs );

fprintf( "Współczynnik kompresji DCT  = %.2f [%%]\n", dctCompressionRate );
fprintf( "Współczynnik kompresji JPEG = %.2f [%%]\n", jpegCompressionRate );


