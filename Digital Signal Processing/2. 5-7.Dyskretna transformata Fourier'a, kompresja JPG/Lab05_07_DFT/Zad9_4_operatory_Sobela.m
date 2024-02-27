%% Wykrywanie krawędzi bez użycia DFT - operatory Sobel'a
clear; clc; close all; 

%% Parametry obróbki
averagingSize = 3;          % Rozmiar macierzy uśredniającej (w pikselach)

%% Ładowanie i wyświetlanie zdjęcia
image = rgb2gray( imread( 'media/village.jpg' ) );

f = figure; ax = axes(f); 
imshow( image, [], 'Parent', ax );
title( ax, "Oryginalne zdjęcie");

%% Filtr uśredniający - rozmycie
averageMatrix = ones( averagingSize );       % Macierz averagingSize x averagingSize samych jedynek 
averageMatrix = averageMatrix ./ sum( averageMatrix, 'all' )  % Normalizacja - suma wszystkich elementów macierzy po normalizacji ma dać 1

averagedImage = imfilter( image, averageMatrix );

f = figure; ax = axes(f); 
imshow( averagedImage, [], 'Parent', ax );
title( ax, "Rozmyte zdjęcie");

%% Wykrywanie krawędzi - różniczkowanie - operatory Sobel'a
sobelOperatorX = [ -1 0 1; -2 0 2; -1 0 1 ]     % Opreator Sobel'a wykrywający krawędzie prostopadłe do osi OX
sobelOperatorY = sobelOperatorX'                % Opreator Sobel'a wykrywający krawędzie prostopadłe do osi OY

edgeDetectX = filter2( sobelOperatorX, image );    % Wykrycie krawędzi OX - splot opreatora i obrazu
edgeDetectY = filter2( sobelOperatorY, image );    % Wykrycie krawędzi OY - splot opreatora i obrazu
edgeDetect = sqrt( edgeDetectX .^ 2 + edgeDetectY .^ 2 );   % Wykrycie krawędzi - moduł obu powyższych obrazów

f = figure; ax = axes(f); 
imshow( edgeDetectX, [], 'Parent', ax );
title( ax, "Wykrycie krawiędzi - X");

f = figure; ax = axes(f); 
imshow( edgeDetectY, [], 'Parent', ax );
title( ax, "Wykrycie krawiędzi - Y");

f = figure; ax = axes(f); 
imshow( edgeDetect, [], 'Parent', ax );
title( ax, "Wykrycie krawiędzi - X oraz Y");
