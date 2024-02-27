%% Kompresja mowy (i dżwięku) za pomocą DCT
clear; clc; close all;

%% Ustawienia kompresji
quality = 0.999;

%% Wczytanie pliku dżwiękowego
[ samples, Fsmp ] = audioread( "media/dialog.mp3" );
% [ samples, Fsmp ] = audioread( "media/dzwonek.mp3" );
% [ samples, Fsmp ] = audioread( "media/pianino_A4.mp3" );

% load( 'strong.mat' )
% Fsmp = fs;
% samples = her;
% samples = him;


%% Odtworzenie dzwięku przed i po kompresji
PlaySound( samples, Fsmp );

compressedMusic = CompressSound( samples, quality );

PlaySound( compressedMusic, Fsmp );

%% Funckja dokonująca kompresji
function [ compressedSamples ] = CompressSound( samples, quality )
    % Obliczenie DCT dźwięku i wyświetlenie widma
    spectrum = dct( samples' );
    uncompressedSpectrum = spectrum;
    figure( 1 ), subplot( 2, 2, 1), plot( abs( spectrum ) ), title( "Widmo oryginalne" );
    
    % Sortowanie widma - od najwyższych prążków do najniższych
    [ sortedSpectrum, indexes ] = sort( abs( spectrum ),'descend');
    subplot( 2, 2, 2), stem( sortedSpectrum ), title( "Widmo posortowane" );
    
    % Obliczenie energii widm poprzez normę: oryginalnego
    fullEnergy = norm( spectrum );
    % i docelowego jako iloczyn energii oryginalnego widma i współczynnika
    % jakości kompresji
    targetEnergy = quality * fullEnergy;
    
    % Wyznaczenie ilości prążków których energia (norma) jest nie mniejsza
    % niż energia docelowa
    noOfUsedCoefs = 1;
    while norm( sortedSpectrum( 1:noOfUsedCoefs ) ) < targetEnergy
        noOfUsedCoefs = noOfUsedCoefs + 1;
    end
    
    % Wyzerowanie wszystkich współczynników o indeksach nie ujętych w
    % powyższej pętli
    spectrum( indexes( noOfUsedCoefs+1:end ) ) = 0;

    % Transformata odwrotna DCT - dźwięk po kompresji
    compressedSamples = idct( spectrum )';

    % Obliczenie ilości użytych współczynników transformaty = współczynnik
    % kompresji
    remainingCoefs = 100*( noOfUsedCoefs / length( spectrum ) );
    fprintf( "Ilość użytych współczynników: %.1f [%%]\n", remainingCoefs );
    
    % Wykresy:
    % Widmo po kompresji
    subplot( 2, 2, 3), plot( abs( spectrum ) ), title( "Widmo po kompresji" );
    % Różnica widm przed i po:
    subplot( 2, 2, 4), plot( abs( spectrum - uncompressedSpectrum ) ), title( "Różnica widm" );
end


