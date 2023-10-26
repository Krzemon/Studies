%% Przesunięcie fazowe sygnału - chwila początku próbkowania
clear; clc; close all;

%% Parametry próbkowania
Fsmp = 16000;       % Częstotliwość próbkowania [Hz]
N = 16;             % Ilość próbek
Nskip = 0;          % Liczba próbek pomijanych z początku ciągu

%% Parametry sygnału
Fsig = 2000;        % Częstotliwość sygnału [Hz]
Phase = 0;          % Faza sygnału [rad]

%% Wywolanie funkcji rysującej widmo

% Wywołujemy funkcjię dla Nskip = 0;
plotSpectrum( Fsmp, N, Nskip, Fsig, Phase );
% Wywołujemy funkcjię dla Nskip = 4;
Nskip = 4;
plotSpectrum( Fsmp, N, Nskip, Fsig, Phase );


%% Funkcja rysująca widmo
function plotSpectrum( Fsmp, N, Nskip, Fsig, Phase )
    % Generacja sygnału i wykres przebiegu czasowego
    Tsmp = 1/Fsmp;
    TotalN = N + Nskip;
    sampledTime = Nskip*Tsmp:Tsmp:(TotalN-1)*Tsmp;
    sampledSignal = sin( 2*pi * Fsig * sampledTime + Phase*pi );
    
    figure, subplot(3,1,1), plot(sampledTime, sampledSignal, 'bx--'), title( 'Sygnał w czasie' );
    xlim( [ 0 2*N*Tsmp] );
    grid on;
    
    % Obliczenie widma - DFT
    spectrum = fft( sampledSignal );
    amplitude = abs( spectrum );        % Nieznormalizowana wartość amplitudy

    Fbase = 1;                      % Częstotliwość bazowa - DO UZUPEŁNIENIA
    amplitudeNorm = amplitude;      % Znormalizowana amplituda - DO UZUPEŁNIENIA
    
    % Wykresy ampliudy i fazy
    sampledFreq = 0:Fbase:(N-1)*Fbase;
    subplot(3,1,2),  stem( sampledFreq, amplitudeNorm ), title( 'Widmo amplitudowe' );
    grid on;

    spectrum( abs(spectrum) < 1e-10 ) = complex( 0 );
    subplot(3, 1, 3), stem( sampledFreq, angle( spectrum ) ./ pi), title( 'Faza' );
    grid on;
end
