%% Dyskretna transformata Fourier'a zdjęć
clear; clc; close all; dbclear all;
dbstop in dbStop;

%% Wczytanie i wyświetlenie zdjęć i ich widma
 for fileName = [ "media/brick_wall.jpg"   "media/building.jpg" "media/church.jpg" "media/mosque.jpg" "media/fields.jpg" "media/bridge.jpg" "media/flower.jpg" ]
     image = rgb2gray( imread( fileName ) );
     width = length( image );
     if width > 800
         size = 50;
     else
         size = 100;
     end
     f = figure; ax = axes(f); 
     imshow( image, 'Parent', ax ,'InitialMagnification', size );
     title( ax, fileName, 'Interpreter', 'none' );
     
     spectrum2dLog = log( 1 + abs( fftshift( fft2( image ) ) ) );
     f = figure; ax = axes(f); 
     imshow( mat2gray( spectrum2dLog ), [], 'Parent', ax , 'InitialMagnification', size );
     title( ax, sprintf( "%s - widmo (skala log)", fileName), 'Interpreter', 'none' );
     
     dbStop();
 
end




%% Pusta funkcja pełniąca rolę pułapki zatrzymującej symulację.
function [] = dbStop()
end