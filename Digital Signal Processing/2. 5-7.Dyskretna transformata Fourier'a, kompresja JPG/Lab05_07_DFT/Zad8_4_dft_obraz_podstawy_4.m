%% Podstawy dyskretnej transformaty Fourier'a 2D - ciąg dalszy
clear; clc; close all; dbclear all;
% Zatrzymanie symulacji przy wywołaniu funkcji dbStop - pusta funkcja
% pełniąca rolę pułapki zatrzymującej symulację.
dbstop in dbStop;

%% Parametry obrazu
imgSize = 400;              % Rozmiar obrazka w pikselach (kwadrat imgSize x imgSize)

%% Parametry sygnału
CircleRadius = 15;          % Promień koła [px]

%% Generacja, analiza i wyświetlanie obrazu - okrąg
% Macierz współrzędnych obrazu
[ x, y ] = meshgrid( -imgSize/2:imgSize/2-1, -imgSize/2:imgSize/2-1 );      
z = sqrt( x.^2 + y.^2 );                        % Równanie okręgu
image = ( z < ( CircleRadius + 1 ) );           % Wyzerowanie wszystkich pikseli bardziej odległych od środka obrazu niż CircleRadius

figure, imshow( image, [] );                    % Wyświetlanie obrazu

%% DFT
spectrum2dLog = log( 1 + abs( fftshift( fft2( image ) ) ) );   % Obliczenie amplitudy DFT w skali logarytmicznej
f = figure; ax = axes(f); 
imshow( mat2gray( spectrum2dLog ), [], 'InitialMagnification', 200, 'Parent', ax );
title( ax, "Widmo - skala logarytmiczna");                     % Wyświetlenie widma amplitudowego

figure, plot( image( imgSize/2+1,:) );                         % Przekrój przez środek obrazka

dbStop();

%% Generacja, analiza i wyświetlanie obrazu - wygładzony okrąg

smoothImage = 1 ./ ( 1 + ( z./15) .^ 2);        % Wygładzenie brzegu koła
figure, imshow( smoothImage );                  % Wyświetlanie obrazu

spectrum2dLog = log( 1 + abs( fftshift( fft2( smoothImage ) ) ) );
f = figure; ax = axes(f); 
imshow( mat2gray( spectrum2dLog ), [], 'InitialMagnification', 200, 'Parent', ax );
title( ax, "Widmo - skala logarytmiczna");                     % Wyświetlenie widma amplitudowego

figure, plot( smoothImage( imgSize/2+1,:) );                   % Przekrój przez środek obrazka



%% Pusta funkcja pełniąca rolę pułapki zatrzymującej symulację.
function [] = dbStop()
end