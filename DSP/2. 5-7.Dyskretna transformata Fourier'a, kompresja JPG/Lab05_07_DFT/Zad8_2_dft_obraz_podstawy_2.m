%% Podstawy dyskretnej transformaty Fourier'a 2D - animacja transformaty odwrotnej
clear; clc; close all; 

%% Parametry obrazu
imgSize = 400;              % Rozmiar obrazka w pikselach (kwadrat imgSize x imgSize)

%% Parametry sygnału
Distance = 10;                % Odległość prążka od środka (DC) w pikselach [px]

%% Generacja widma(!), transformata odwrotna i wyświetlenie obrazu
% Nieskończona pętla (Stop w Matlabi'e żeby zakończyć)
while 1
    % Przesuwamy prążek po osi OX od -Period do +Period wokół środka
    for shiftX = -Distance:Distance
        % Inicjalizacja widma - zespolone zera
        spectrum = complex( zeros( imgSize ) );
        
        % Współrzędna Y - od Period do 0, w drugiej połowie od 0 do Period
        shiftY = Distance - abs( shiftX );

        % Ustawiamy prążek w X,Y na 1 (oraz odpowiadający mu prążęk
        % sprzężony (obraz jest rzeczywisty) 
        spectrum( (imgSize/2) + shiftY, (imgSize/2) + shiftX ) = complex( 1 );
        spectrum( (imgSize/2) - shiftY, (imgSize/2) - shiftX) = complex( 1 );
        
        % Wyświetlenie widma
        f = figure( 1 );
        f.Position( 3:4 ) = [ 1200, 600 ];
        figure(1), subplot( 1, 2, 1), imshow( mat2gray( log( 1 + abs( spectrum ) ) ) );
        
        % Transformata odwrotna
        image = abs( ifft2( spectrum ) );
        
        % Wyświetlenie obrazu otrzymanego w wyniku transformaty odwrotnej
        subplot( 1, 2, 2), imshow( mat2gray( image ), [] );
    
        pause(0.5);
    end
end