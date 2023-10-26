%% Filtracja dolnoprzepustowa zdjęć
clear; clc; close all; 

%% Parametry filtracji
filterRatio = 0.4;              % Stosunek częstotliwości granicznej do częstotliwości Nyquista ( <1 )
filterType = 3;                 % Typ filtru:
                                %  1 - koło (ostre odcięcie)
                                %  2 - filtr gaussowski
                                %  3 - filtr Butterworth-a
butterFilterOrder = 2;          % Rząd filtru Butterworth-a

%% Ładowanie i wyświetlanie zdjęcia
image = rgb2gray( imread( 'media/village.jpg' ) );
figure, imshow( image, [] );

%% DFT zdjęcia
spectrum2D = fftshift( fft2( image ) );
figure, imshow( mat2gray( log( 1 + abs( spectrum2D ) ) ) );

%% Tworzenie funkcji filtru
[ width, height ] = size( image );      % Rozmiar zdjęcia
dim = min( [ width height ] ) / 2;      % Odległość od środka do krótszej z krawędzi (w przybliżeniu okres Nyquista)

% Przestrzeń współrzędnych filtru
[ x, y ] = meshgrid( -(height/2) : (height/2)-1, -(width/2) : (width/2)-1 );

switch filterType
    % Trywialny filtr - okrąg o zadanym promieniu
    case 1
        z =  sqrt( x.^2 + y.^2 );               
        filterFunction =  z < ( dim * filterRatio );
    % Filtr gaussowski
    case 2
        filterFunction = fspecial( 'gaussian', [ width, height ], 0.5 * dim * filterRatio );
        % Renormalizacja do zakresu 0--1
        filterFunction = mat2gray( filterFunction );
    case 3
        filterFunction = 1. - 1 ./ ( 1. + ( ( dim * filterRatio * 0.5 ) ./ ( x .^ 2 + y .^ 2 ) .^ 0.5 ) .^ ( 2*butterFilterOrder ) );
end


figure( 100 ), colormap( parula(64) );
mesh( x, y , filterFunction );

%% Filtracja i wyświetlenie widma
filteredSpectrum = spectrum2D .* filterFunction;

figure, imshow( mat2gray( log( 1 + abs( filteredSpectrum ) ) ) );

%% Transformata odwrotna i wyświetlenie zdjęć
filteredImage = abs( ifft2( filteredSpectrum ) );

figure, imshow( filteredImage, [] );
