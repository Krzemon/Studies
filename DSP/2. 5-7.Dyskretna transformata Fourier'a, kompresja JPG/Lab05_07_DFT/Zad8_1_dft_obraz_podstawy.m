%% Podstawy dyskretnej transformaty Fourier'a 2D
clear; clc; close all; dbclear all;
dbstop in dbStop;


%% Parametry obrazu
imgSize = 400;              % Rozmiar obrazka w pikselach (kwadrat imgSize x imgSize)

%% Parametry sygnału
Period = 20;                % Okres sinusa wyrażona w pikselach [px]

%% Generacja obrazu - pionowe linie
pixelCoords = 0:imgSize-1;                               % Wektor współrzędnych jednego wiersza obrazu
imageRow = 0.5 + 0.5*sin( 2*pi*pixelCoords / Period );   % Generacja jednego wiersza obrazu - sinus
imageVertical = repmat( imageRow, imgSize, 1 );          % Powielenie wiersza

%% Wyświetlanie obrazu i jego jednego wiersza
figure(1), subplot(2,1,1), imshow( imageVertical, [] );  % Wyświetlanie obrazu
subplot(2,1,2), plot( imageVertical( 1,: ) );            % Wykres pierwszego wiersza

%% 2D DFT
spectrum2d = fftshift( fft2( imageVertical ) );

%% Wyświetlenie widma - skala liniowa
amplitude = abs( spectrum2d );
f = figure; ax = axes(f); 
imshow( amplitude, [], 'InitialMagnification', 200, 'Parent', ax );
title( ax, "Widmo - skala liniowa");

%% Wyświetlenie widma - skala logarytmiczna
spectrum2dLog = log( 1 + abs( spectrum2d ) );
f = figure; ax = axes(f); 
imshow( mat2gray( spectrum2dLog ), [], 'InitialMagnification', 200, 'Parent', ax );
title( ax, "Widmo - skala logarytmiczna");

%% Wykresy środkowego wiersza widm
figure, subplot(2,1,1), plot( pixelCoords, amplitude( imgSize/2 + 1,: ) ), title( "Widmo - skala liniowa" );
subplot(2,1,2), plot( pixelCoords, spectrum2dLog( imgSize/2 + 1,: ) ), title( "Widmo - skala logarytmiczna");    

dbStop();

%% Generacja, analiza i wyświetlanie obrazu - poziome linie
pixelCoords = 0:imgSize-1;                                       % Wektor współrzędnych jednego wiersza obrazu
imageColumn = 0.5 + 0.5*sin( 2*pi*pixelCoords / Period );        % Generacja jednego wiersza obrazu - sinus
imageHorizontal = repmat( imageColumn', 1, imgSize );            % Powielenie wiersza

figure, imshow( imageHorizontal, [] );                           % Wyświetlanie obrazu

spectrum2d = fftshift( fft2( imageHorizontal ) );

amplitude = abs( spectrum2d );
f = figure; ax = axes(f); 
imshow( amplitude, [], 'InitialMagnification', 200, 'Parent', ax );
title( ax, "Widmo - skala liniowa");

%% Pusta funkcja pełniąca rolę pułapki zatrzymującej symulację.
function [] = dbStop()
end