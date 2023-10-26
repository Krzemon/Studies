%% Widmo przebiegu prostokątnego o nie-50% współczynniku wypełnienia
clear; clc; close all;

%% Parametry sygnału i próbkowania
N = 200;                    % Długość ciągu próbek
T = 50;                     % Okres przebiegu prostokątnego
K = 20;                     % Szerokość dodatniej połówki przebiegu (przebieg idealny: K = T / 2 )

%% Generacja sygnału
sampledTime = 0:(N-1);                          % Wektor skwantowanego czasu = indeksy próbek
sigPeriod = [ ones( 1, K) zeros( 1, T-K ) ];    % Jeden okres przebiegu
signal = repmat( sigPeriod, 1, N/T );           % Powielenie okresu N/T razy

%% Wykresy

figure(1), subplot( 2, 1, 1), plot( sampledTime, signal, 'bo--' ), title( "Przebieg czasowy" );
grid on;

spectrum = abs( fft( signal ) );
subplot( 2, 1, 2), stem( sampledTime, spectrum, 'b' ), title( "Widmo amplitudowe" );
hold on; grid on;
stem( sampledTime( mod( sampledTime, N/T ) == 0 ), spectrum( mod( sampledTime, N/T ) == 0 ), 'r' );

%% Widmo teoretycznie - jądro Dirichlet'a
realTime = 0:0.001:(N-1);    % Wektor kwazi-ciągłego czasu

X_m = (N/T) * sin( pi*realTime*K / N ) ./ sin( pi*realTime / N );

plot( realTime, abs( X_m), 'k' );
legend( "DFT", "Harmoniczne Fsig", sprintf( "Dirichlet dla K=%d", K ) );
hold off;

fprintf( "Współczynnik wypełnienia = %.2f [%%]\n", 100*(K/T) );
