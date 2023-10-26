%% Podstawy dyskretnej transformaty Fourier'a 2D - ciąg dalszy
clear; clc; close all; dbclear all;
dbstop in dbStop;

%% Parametry obrazu
imgSize = 400;              % Rozmiar obrazka w pikselach (kwadrat imgSize x imgSize)

%% Parametry sygnału
Period = 20;                % Okres sinusa wyrażona w pikselach [px]

%% Generacj obrazu - poziome linie
pixelCoords = 0:imgSize-1;                                       % Wektor współrzędnych jednego wiersza obrazu
imageColumn = 0.5 + 0.5*sin( 2*pi*pixelCoords / Period );        % Generacja jednego wiersza obrazu - sinus
imageHorizontal = repmat( imageColumn', 1, imgSize );            % Powielenie wiersza

%% Generacja, analiza i wyświetlanie obrazu - kombinacja poziomych i pionowych linii
imageVertical = imageHorizontal';
imageVH = [ imageVertical( :,1:imgSize/2 ) imageHorizontal( :,imgSize/2+1:end ) ];

figure, imshow( imageVH, [] );                 % Wyświetlanie obrazu

spectrum2d = fftshift( fft2( imageVH ) );

amplitude = abs( spectrum2d );
f = figure; ax = axes(f); 
imshow( amplitude, [], 'InitialMagnification', 200, 'Parent', ax );
title( ax, "Widmo - skala liniowa");

dbStop();

spectrum2dLog = log( 1 + abs( spectrum2d ) );
f = figure; ax = axes(f); 
imshow( mat2gray( spectrum2dLog ), [], 'InitialMagnification', 200, 'Parent', ax );
title( ax, "Widmo - skala logarytmiczna");

dbStop();

%% Generacja, analiza i wyświetlanie obrazu - skośne linie
imageVerticalBig = repmat( imageVertical, 2);

imageObliqueBig = imrotate( imageVerticalBig, 45 );
reduceSize = ( length( imageObliqueBig ) - imgSize ) / 2;
imageOblique = imageObliqueBig( reduceSize:reduceSize+imgSize, reduceSize:reduceSize+imgSize );

figure, imshow( imageOblique, [] );                 % Wyświetlanie obrazu

spectrum2d = fftshift( fft2( imageOblique ) );

amplitude = abs( spectrum2d );
f = figure; ax = axes(f); 
imshow( amplitude, [], 'InitialMagnification', 200, 'Parent', ax );
title( ax, "Widmo - skala liniowa");


dbStop();

spectrum2dLog = log( 1 + abs( spectrum2d ) );
f = figure; ax = axes(f); 
imshow( mat2gray( spectrum2dLog ), [], 'InitialMagnification', 200, 'Parent', ax );
title( ax, "Widmo - skala logarytmiczna");

figure, plot( imageOblique( imgSize/2, : ), 'x-' );


%% Pusta funkcja pełniąca rolę pułapki zatrzymującej symulację.
function [] = dbStop()
end