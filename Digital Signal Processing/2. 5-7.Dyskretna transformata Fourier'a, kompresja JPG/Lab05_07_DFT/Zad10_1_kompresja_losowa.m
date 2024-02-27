%% Kompresja stratna losowa - wyrzucamy losowo niektóre z pikseli...
clear; clc; close all;

%% Parametry kompresji
quality = 100;        % Współczynnik jakości po kompresji [%] (zakres 1 - 100 )

%% Ładowanie i wyświetlanie zdjęcia
image = imread( 'media/village.jpg' );

f = figure; ax = axes(f); 
imshow( image, [], 'Parent', ax );
title( ax, "Oryginalne zdjęcie");

%% Generacja zestawu liczb pseudolosowych
qualityFrac = quality / 100;

[ height, width, colors ] = size( image );

mask = rand( height, width, colors ) > qualityFrac;

% mask = rand( height, width ) > qualityFrac;
% mask = repmat( mask, 1, 1, colors );

%% Kompresja
compressedImage = image;
compressedImage( mask ) = 0;

f = figure; ax = axes(f); 
imshow( compressedImage, [], 'Parent', ax );
title( ax, "Skompresowane zdjęcie");

%% Współczynnik kompresji - liczba zer w macierzy
noOfPixels = width * height * colors;

idxImage = ( image == 0 );
zeroPixelsImage = sum( idxImage( : ) );

idxCompressedImage = ( compressedImage == 0 );
zeroPixelsCompressedImage = sum( idxCompressedImage( : ) );

fprintf( "Ilość składowych RGB (pikseli*3) w zdjęciu        = %d\n", noOfPixels );
fprintf( "Ilość zer w oryginalnym zdjęciu                   = %d\n", zeroPixelsImage );
fprintf( "Współczynnik 'kompresji' w oryginalnym zdjęciu    = %.2f%%\n", 100 * (zeroPixelsImage / noOfPixels ) );
fprintf( "Ilość zer w skompresowanym zdjęciu                = %d\n", zeroPixelsCompressedImage );
fprintf( "Współczynnik 'kompresji' w skompresowanym zdjęciu = %.2f%%\n", 100 * (zeroPixelsCompressedImage / noOfPixels ) );

