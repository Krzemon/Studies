%% Dwuwymiarowy filtr FIR
clear; clc; close all;


%% Parametry filtru
filterRatio = 0.2;                  % Stosunek częstotliwości granicznej do częstotliwości Nyquista ( <1 )
filterOrder = 20;                   % Rząd filtru
window = blackman( filterOrder );    % Funckja okna filtru

%% Ładowanie i wyświetlanie zdjęcia
image = rgb2gray( imread( 'media/village.jpg' ) );
figure( 1 ), imshow( image, [] );

%% Definicja filtru

% Tworzymy przestrzeń równomiernie rozłożonych wartości od -0.5 do 0.5
[ fx, fy ] = freqspace( filterOrder, 'meshgrid' );
% Obliczamy równanie okręgu - odległość od środka przestrzeni
r = sqrt( fx .^ 2 + fy .^ 2 );

% Tworzymy idealną (żądaną) funkcję przenoszenia
% Wypełniamy całą przestrzeń wartością 1 (filtr all-pass)
idealFreqResponse = ones( filterOrder ); 

% a następnie zerujemy wszystkie współczynniki odpowiadające
% częstotliwościom większym od filterRatio
idealFreqResponse( (r > filterRatio) ) = 0;

% Obliczamy współczynniki filtru za pomocą wbudowanej funkcji Matlab'a
FIRcoefs = fwind1( idealFreqResponse, window );

%% Wykresy
% Idealna, zadana funkcja przenoszenia
% PARULA Blue-green-orange-yellow color map
figure( 2 ), colormap( parula(64) );
mesh( fx, fy , idealFreqResponse );

% Funkcja przenoszenia wyliczona ze współczynników
figure( 3 ), freqz2( FIRcoefs );

%% Filtracja i wyświetlenie obrazu
% Filtracja - splot obrazu i współczynników filtru FIR
filteredImage = imfilter( image, FIRcoefs );

% Wyświetlenie przefiltrowanego obrazu
figure( 4 ), imshow( filteredImage, [] );