%% Wyostrzanie zdjęć
clear; clc; %close all; 

%% Parametry obróbki
filterRatio = 0.2;               % Stosunek częstotliwości granicznej do częstotliwości Nyquista ( <1 )
butterFilterOrder = 10;           % Rząd filtru Butterworth-a
sharpeningCoef = 0.4;           % Współczynnik wyostrzania

%% Ładowanie i wyświetlanie zdjęć
image = rgb2gray( imread( 'media/ksiaz.jpg' ) );

figure( 1 ), imshow( image, [] );

%% DFT zdjęcia
spectrum2D = fftshift( fft2( image ) );

%% Tworzenie funkcji filtru
[ width, height ] = size( image );      % Rozmiar zdjęcia
dim = min( [ width height ] ) / 2;      % Odległość od środka do krótszej z krawędzi (w przybliżeniu okres Nyquista)
% Przestrzeń współrzędnych filtru
[ x, y ] = meshgrid( -(height/2) : (height/2)-1, -(width/2) : (width/2)-1 );
filterFunction = 1. - 1 ./ ( 1. + ( ( dim * filterRatio * 0.5 ) ./ ( x .^ 2 + y .^ 2 ) .^ 0.5 ) .^ ( 2*butterFilterOrder ) );

%% Filtracja widma
filteredSpectrum = spectrum2D .* filterFunction;

%% Transformata odwrotna
filteredImage = uint8( 255 * mat2gray( abs( ifft2( filteredSpectrum ) ) ) );

%% Wysotrzanie:
% Obraz wyostrzony = Obraz oryginalny + A*[ Obraz oryginalny - Obraz uśredniony ]
sharpenedImage = image + sharpeningCoef .* ( image - filteredImage );

figure( 2 ), imshow( sharpenedImage, [] );
