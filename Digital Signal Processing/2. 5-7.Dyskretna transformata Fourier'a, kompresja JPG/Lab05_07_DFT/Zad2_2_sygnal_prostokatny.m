%% Widmo sygnału prostokątnego
clear; clc; close all; dbclear all;
% Zatrzymanie symulacji przy wywołaniu funkcji dbStop - pusta funkcja
% pełniąca rolę pułapki zatrzymującej symulację.
dbstop in dbStop;

%% Parametry sygnału i próbkowania
N = 200;                    % Długość ciągu próbek
K = N / 8;                  % Szerokość impulsu prostokątnego

sampledTime = 0:(N-1);      % Wektor skwantowanego czasu = indeksy próbek

%% Głowna część skryptu
% Generujemy trzy przypadki (każdy z dwoma pod-przypadkami) impulsów
% prostokątnych
for wersja = 0:2
    
    %% Przebieg "lewy"
    % Dla wersji 0 oraz 1 - pojedynczy impuls położony w 0 albo 2*K
    if wersja < 2
        n0 = 2*K*wersja;
        rectLeft = [ zeros(1,n0) ones(1,K) zeros(1, N-K-n0) ];
        showBin = 7;
    % Dla wersji 2 - wynik (suma) z poprzednich wykonań
    else
        n0 = 0;
        rectLeft = [ zeros(1,n0) ones(1,K) zeros(1, N-K-n0) ];
        n0 = N/2;
        rectLeft  = rectLeft + [ zeros(1,n0) ones(1,K) zeros(1, N-K-n0) ];
        showBin = 6;
        n0 = 0;
    end
    
    % Wykres przebiegu czasowego
    figure(wersja + 1), subplot( 3, 3, 1 ), plot( sampledTime, rectLeft, 'bo-' ), title( sprintf( "n0=%d - przebieg czasowy", n0 ) );
    
    % Obliczenie widma
    spectrum = fft( rectLeft );

    % Wykres amplitudy
    amplitude = abs( spectrum );
    subplot( 3, 3, 4 ), stem( sampledTime, amplitude, 'b' ), title( sprintf( "n0=%d - widmo amplitudowe", n0 ) );
    xlim( [ 0 N/2 ] );
    hold on;
    stem( sampledTime( showBin+1 ), amplitude( showBin+1 ), 'r' );
    
    % Obliczenie fazy i wykres
    phaseLeft = angle( spectrum ) / pi;
    subplot( 3, 3, 7 ), stem( sampledTime, phaseLeft, 'b' ), title( sprintf( "n0=%d - faza", n0 ) );
    xlim( [ 0 N/2 ] );
    hold on;
    stem( sampledTime( showBin+1 ), phaseLeft( showBin+1 ), 'r' );
    
    % Wypisanie wartości 7. lub 6. prążka (zależnie od wersji)
    fprintf( "Wartość %d. prązka sygnału n0=%d  = %.3f + %.3fj\n", showBin, n0, real( spectrum( showBin+1 )), imag( spectrum( showBin+1 )) );
    
    %% Przebieg "prawy"
    % Dla wersji 0 oraz 1 - pojedynczy impuls położony w N/2 albo N/2 + 2*K
    if wersja < 2
        n0 = n0 + N/2;
        rectRight = [ zeros(1,n0) ones(1,K) zeros(1, N-K-n0) ];
     % Dla wersji 2 - wynik (suma) z poprzednich wykonań
    else
        n0 = 2*K;
        rectRight = [ zeros(1,n0) ones(1,K) zeros(1, N-K-n0) ];
        n0 = n0 + N/2;
        rectRight  = rectRight + [ zeros(1,n0) ones(1,K) zeros(1, N-K-n0) ];
        n0 = 2*K;
    end
    
    % Wykres przebiegu czasowego
    subplot( 3, 3, 2), plot( sampledTime, rectRight, 'bo-' ), title( sprintf( "n0=%d - przebieg czasowy", n0 ) );
    
    % Obliczenie widma
    spectrum = fft( rectRight );

    % Wykres amplitudy
    amplitude = abs( spectrum );
    subplot( 3, 3, 5 ), stem( sampledTime, amplitude, 'b' ), title( sprintf( "n0=%d - widmo amplitudowe", n0 ));
    xlim( [ 0 N/2 ] );
    hold on;
    stem( sampledTime( showBin+1 ), amplitude( showBin+1 ), 'r' );
    
    % Obliczenie fazy i wykres
    phaseRight = angle( spectrum ) / pi;
    subplot( 3, 3, 8 ), stem( sampledTime, phaseRight, 'b' ), title( sprintf( "n0=%d - faza", n0 ));
    xlim( [ 0 N/2 ] );
    hold on;
    stem( sampledTime( showBin+1 ), phaseRight( showBin+1 ), 'r' );

    % Wypisanie wartości 7. lub 6. prążka (zależnie od wersji)
    fprintf( "Wartość %d. prązka sygnału n0=%d  = %.3f + %.3fj\n", showBin, n0, real( spectrum( showBin+1 )), imag( spectrum( showBin+1 )) );
    
    % Zatrzymanie symulacji przed kolejnym krokiem
    dbStop();

    % Obliczenie modułu różnicy faz i wykres
    phaseDiff = abs( phaseLeft - phaseRight );
    % subplot( 3, 3, 9 ), stem( sampledTime( abs( spectrum ) > 0.001 ), phaseDiff( abs( spectrum ) > 0.001 ), 'b'), title( "Moduł różnicy faz" );
    subplot( 3, 3, 9 ), stem( sampledTime, phaseDiff, 'b'), title( "Moduł różnicy faz" );
    xlim( [ 0 N/2 ] );
    hold on;
    stem( sampledTime( showBin+1 ), phaseDiff( showBin+1 ), 'r' );
    
    % Zatrzymanie symulacji przed kolejnym krokiem
    dbStop();
    
    %% Suma przebiegów "lewego" i "prawego"
    rectBoth = rectLeft + rectRight;
    
    % Wykres przebiegu czasowego
    subplot( 3, 3, 3 ), plot( sampledTime, rectBoth, 'bo-' ), title("Suma - przebieg czasowy" );
    
    % Obliczenie widma
    spectrum = fft( rectBoth );

    % Wykres amplitudy
    amplitude = abs( spectrum );
    subplot( 3, 3, 6 ), stem( sampledTime, amplitude, 'b' ), title("Suma - widmo amplitudowe" );
    xlim( [ 0 N/2 ] );
    hold on;
    stem( sampledTime( showBin+1 ), amplitude( showBin+1 ), 'r' );
    
    % Zatrzymanie symulacji przed kolejnym krokiem
    if wersja < 2
        dbStop();
    end
end

%% Pusta funkcja pełniąca rolę pułapki zatrzymującej symulację.
function [] = dbStop()
end