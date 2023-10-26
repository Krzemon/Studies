%% Rozdzielczość transformaty - zero padding
clear; clc; close all;

%% Parametry zero padding
zeroPadding = 1000;

%% Parametry próbkowania
Fsmp = 16000;       % Częstotliwość próbkowania [Hz]
N = 3200;           % Ilość próbek

%% Parametry sygnału
Fsig1 = 3000;       % Częstotliwość sygnału pierwszego [Hz]
Amp1 = 0.01;        % Amplituda sygnału pierwszego [V]

Fsig2 = 3047;       % Częstotliwość sygnału drugiego [Hz]
Amp2 = 1;           % Amplituda sygnału drugiego [V] 

%% Generacja sygnału i wykres przebiegu czasowego
Tsmp = 1 / Fsmp;    % Okres próbkowania [s]

% Wektor skwantowanego czasu
sampledTime = 0:Tsmp:(N-1)*Tsmp;                                           
% Wektor skwantowanego czasu włączając zero padding
fullSampledTime = -zeroPadding*Tsmp:Tsmp:(N+zeroPadding-1)*Tsmp;                                           

% Wektor wartości próbek sygnału
sampledSignal1 = Amp1 * sin( 2*pi * Fsig1 * sampledTime );
sampledSignal2 = Amp2 * sin( 2*pi * Fsig2 * sampledTime );
sampledSignal = sampledSignal1 + sampledSignal2 ;     % Wektor wartości próbek sygnału
fullSampledSignal = [ zeros(1, zeroPadding) sampledSignal zeros( 1, zeroPadding ) ];

figure(1), subplot(2,1,1), plot( fullSampledTime, fullSampledSignal ), title( 'Sygnał w czasie' );
grid on;

%% Obliczenie widma - DFT
spectrum = fft( fullSampledSignal );    % Obliczamy DFT używając algorytmu FFT

%% Widmo amplitudowe
amplitude = abs( spectrum );        % Nieznormalizowana wartość amplitudy

fullN = N + 2*zeroPadding;
Fbase = Fsmp / fullN;               % Częstotliwość bazowa
amplitudeNorm = amplitude;          % Znormalizowana amplituda - DO UZUPEŁNIENIA

sampledFreq = 0:Fbase:(fullN-1)*Fbase;  % Wektor skwantowanych częstotliwości

subplot(2,1,2),  semilogy( sampledFreq, amplitudeNorm ), title( 'Widmo amplitudowe' );
xlim( [ 0 Fsmp/2 ] );
xlabel("Częstotliwość [Hz]")
ylabel("Amplituda")
grid on;

[ value, index ] = max( amplitudeNorm( 1, 1:fullN/2 ) );
fprintf( "Położenie maksimum widma = %.3f [Hz]\n", ( index-1 )* Fbase );
