%% Filtracja pasmowa zdjęć
clear; clc; close all; 

%% Parametry filtracji
highPassFilterRatio = 0.7;      % Stosunek częstotliwości granicznej do częstotliwości Nyquista ( <1 )
lowPassFilterRatio = 0.2;
butterFilterOrder = 2;          % Rząd filtru Butterworth-a
keepDC = 1;                     % Czy filtr ma zachować prążek dla DC (0 lub 1)

%% Ładowanie i wyświetlanie zdjęcia
image = rgb2gray( imread( 'media/village.jpg' ) );
% figure(1), imshow( image, [] );

%% DFT zdjęcia
spectrum2D = fftshift( fft2( image ) );

%% Tworzenie funkcji filtru Butterworth-a
[ width, height ] = size( image );      % Rozmiar zdjęcia
dim = min( [ width height ] ) / 2;      % Odległość od środka do krótszej z krawędzi (w przybliżeniu okres Nyquista)

% Przestrzeń współrzędnych filtru
[ x, y ] = meshgrid( -(height/2) : (height/2)-1, -(width/2) : (width/2)-1 );

highPassFilterFunction = 1 ./ ( 1. + ( ( dim * highPassFilterRatio ) ./ ( x .^ 2 + y .^ 2 ) .^ 0.5 ) .^ ( 2*butterFilterOrder ) );
lowPassFilterFunction = 1. - 1 ./ ( 1. + ( ( dim * lowPassFilterRatio ) ./ ( x .^ 2 + y .^ 2 ) .^ 0.5 ) .^ ( 2*butterFilterOrder ) );

bandpassFilter = ( lowPassFilterFunction .* highPassFilterFunction );
bandstopFilter = max( max( bandpassFilter ) ) - bandpassFilter;

f = figure; ax = axes(f); 
imshow( mat2gray( bandpassFilter ), [], 'Parent', ax );
title( ax, 'Filtr pasmowo-przepustowy' );

f = figure; ax = axes(f); 
imshow( mat2gray( bandstopFilter ), [], 'Parent', ax );
title( ax, 'Filtr pasmowo-zaporowy' );

% Zachowanie prążka DC - wstawienie jedynki w funkcję filtru dokładnie w
% środku zdjęcia 
bandpassFilter( width/2+1, height/2+1 ) = keepDC;

%% Filtracja i wyświetlenie widma
bandpassSpectrum = spectrum2D .* bandpassFilter;
bandstopSpectrum = spectrum2D .* bandstopFilter;

f = figure; ax = axes(f); 
imshow( mat2gray( log( 1 + abs( bandpassSpectrum ) ) ) , 'Parent', ax );
title( ax, 'Widmo - filtr pasmowo-przepustowy' );

f = figure; ax = axes(f); 
imshow( mat2gray( log( 1 + abs( bandstopSpectrum ) ) ) , 'Parent', ax );
title( ax, 'Widmo - filtr pasmowo-zaporowy' );


%% Transformata odwrotna i wyświetlenie zdjęć
bandpassImage = abs( ifft2( bandpassSpectrum ) );
bandstopImage = abs( ifft2( bandstopSpectrum ) );

f = figure; ax = axes(f); 
imshow( mat2gray( bandpassImage ), [], 'Parent', ax );
title( ax, 'Zdjęcie - filtr pasmowo-przepustowy' );

f = figure; ax = axes(f); 
imshow( mat2gray( bandstopImage ), [], 'Parent', ax );
title( ax, 'Zdjęcie - filtr pasmowo-zaporowy' );
