%% Okna - minimalizacja wycieków
clear; clc; close all;

%% Parametry próbkowania
Fsmp = 16000;       % Częstotliwość próbkowania [Hz]
N = 1600;           % Ilość próbek

%% Parametry sygnału
Fsig1 = 3000;       % Częstotliwość sygnału pierwszego [Hz]
Amp1 = 0.01;           % Amplituda sygnału pierwszego [V]

Fsig2 = 3045;       % Częstotliwość sygnału drugiego [Hz]
Amp2 = 1;           % Amplituda sygnału drugiego [V]    

%% Generacja sygnału i wykres przebiegu czasowego
Tsmp = 1 / Fsmp;    % Okres próbkowania [s]

sampledTime = 0:Tsmp:(N-1)*Tsmp;                                            % Wektor skwantowanego czasu
% Wektor wartości próbek sygnału
sampledSignal1 = Amp1 * sin( 2*pi * Fsig1 * sampledTime );
sampledSignal2 = Amp2 * sin( 2*pi * Fsig2 * sampledTime );
sampledSignal = sampledSignal1 + sampledSignal2 ;     % Wektor wartości próbek sygnału

figure(1), subplot(2,1,1), plot(sampledTime, sampledSignal ), title( 'Sygnał w czasie' );
grid on;

%% Obliczenie widma - DFT
spectrum = fft( sampledSignal );    % Obliczamy DFT używając algorytmu FFT

%% Widmo amplitudowe
amplitude = abs( spectrum );        % Nieznormalizowana wartość amplitudy

Fbase = Fsmp / N;                   % Częstotliwość bazowa
amplitudeNorm = amplitude;          % Znormalizowana amplituda - DO UZUPEŁNIENIA

sampledFreq = 0:Fbase:(N-1)*Fbase;  % Wektor skwantowanych częstotliwości

subplot(2,1,2),  semilogy( sampledFreq, amplitudeNorm ), title( 'Widmo amplitudowe' );
xlim( [ (Fsig1 - 500) (Fsig2 + 500) ] );
grid on;

%% Generacja funcji okien
window = zeros( 4, N );
window( 1,: ) = triang( N );
window( 2,: ) = blackman( N );
window( 3,: ) = hamming( N );
window( 4,: ) = hanning( N );
windowNames = [ "Trójkąt" "Blackman" "Hamming" "Hanning" ];


%% Wyświetlenie funkcji okien

windowAmplitudeNorm = zeros( 4, N );

figure(2);  clf;
for windowIndex = 1:4
    subplot( 3, 4, windowIndex );
    plot( window( windowIndex, : ) );
    grid on
    
    windowedSignal = sampledSignal .* window( windowIndex, : );
    subplot( 3, 4, windowIndex+4 );
    plot( sampledTime, windowedSignal ), title( windowNames( windowIndex ) );
    ylim( [ -1.2 1.2 ] );
    grid on
    
    % Widmo sygnału obłożonego oknem
    spectrum = fft( windowedSignal );
    amplitude = abs( spectrum );                % Nieznormalizowana wartość amplitudy
    windowAmplitudeNorm( windowIndex, : ) = amplitude;    % Znormalizowana amplituda - DO UZUPEŁNIENIA

    subplot( 3, 4, windowIndex+8 );
    semilogy( sampledFreq, windowAmplitudeNorm( windowIndex, : ) );
    xlim( [ (Fsig1 - 500) (Fsig2 + 500) ] );
    grid on;
end

%% Wszystkie widma na jednym wykresie
figure(3);
semilogy( sampledFreq, amplitudeNorm );
xlim( [ (Fsig1 - 500) (Fsig2 + 500) ] );
grid on;
hold on;
for windowIndex = 1:4
    semilogy( sampledFreq, windowAmplitudeNorm( windowIndex, : ) );
end

legend( [ "Prostokąt" windowNames] );
