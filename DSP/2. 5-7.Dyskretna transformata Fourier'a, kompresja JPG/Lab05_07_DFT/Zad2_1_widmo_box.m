%% Widmo impulsu prostokątnego (box)
clear; clc; close all; dbclear all;
% Zatrzymanie symulacji przy wywołaniu funkcji dbStop - pusta funkcja
% pełniąca rolę pułapki zatrzymującej symulację.
dbstop in dbStop;

%% Parametry próbkowania
Fsmp = 1;           % Bezwymiarowa częstotliwość próbkowania
N = 64;             % Ilość próbek

%% Parametry sygnalu
K = N;              % Szerokość impulsu prostokątnego [próbki]
 %n0 = -5;            % Początek impulsu prostokątnego (przedział próbkowania rozciąga się od -N/2+1 do N/2)
 n0 = -(K-1)/2;      % Początek impulsu prostokątnego - symetrycznie względem zera.

%% Generacja sygnału
realTime = ( -N/2 ):0.001:( N/2-1 );    % Wektor kwazi-ciągłego czasu (dla wykresów przebiegów teoretycznych)
                                        % Przesunięty o 1 względem
                                        % sampledTime ze względu na
                                        % Matlab-owe indeksowanie od 1
                                        % zamiast zera.
sampledTime = ( -N/2+1 ):( N/2 );       % Wektor skwantowanego czasu = indeksy próbek

sampledSignal = zeros( 1, N );          % Inicjalizacja wekora sygnału zerami
sampledSignal( 1, ( n0 + N/2 ):( n0+K-1+N/2 ) ) = ones( 1, K );  % Dodanie jedynek - prostokąt

figure(1), stem( sampledTime, sampledSignal, 'b' ), title( "Prebieg czasowy - prostokąt" );

%% Widmo sygnału
spectrum = fftshift( fft( sampledSignal ) );    % Obliczenie DFT. Funkcja 
                                                % fftshift przesuwa
                                                % widmo tak, że rozciąga
                                                % się od -Fsmp/2 do Fsmp/2
                                                % zamiast 0 -- Fsmp.

figure(2), stem( sampledTime-1, abs( spectrum ), 'b');
hold on; grid on;

%dbStop();

%% Widmo teoretyczne (prawie...) - sinc
figure(2), plot( realTime, K*abs( sinc( realTime * (K/N) ) ), 'r');
legend( "DFT", "sinc" );

%dbStop();

%% Widmo teoretycznie - jądro Dirichlet'a
X_m = exp( i* ( 2*pi*realTime / N ) * ( -n0 - (K-1)/2 ) );
X_m = X_m .* sin( pi*realTime*K / N ) ./ sin( pi*realTime / N );

figure(2), plot( realTime, abs( X_m), 'k' );

legend( "DFT", "sinc", "Dirichlet" );
hold off;

%% Literatura
% Richard G. Lyons - Understanding Digital Signal Processing (2nd Edition)
%  - Chapter Three. The Discrete Fourier Transform: The DFT of rectangular functions
pozycja_min = find(abs(spectrum) == min(abs(spectrum((N/2+2):N)))) - (N/2+1);
pozycja_min = pozycja_min / N * Fsmp;
pozycja_min 
%% Pusta funkcja pełniąca rolę pułapki zatrzymującej symulację.
function [] = dbStop()
end