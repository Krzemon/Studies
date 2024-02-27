%% Rozdzielczość transformaty - zero padding
clear; clc; close all;

%% Parametry próbkowania
Fsmp = 16000;       % Częstotliwość próbkowania [Hz]
N = 55000;          % Maksymalna liczba próbek

%% Parametry sygnału
Fsig = 1000;       % Częstotliwość sygnału pierwszego [Hz]
Amp = 0.5;         % Amplituda sygnału pierwszego [V]
NoiseAmp = 20;     % Amplituda szumu białego


%% Generacja sygnału i wykres przebiegu czasowego
Tsmp = 1 / Fsmp;    % Okres próbkowania [s]

% Wektor skwantowanego czasu
sampledTime = 0:Tsmp:(N-1)*Tsmp;                                           

% Wektor wartości próbek sygnału
sampledSignal = Amp * sin( 2*pi * Fsig * sampledTime );
% Generacja szumu
noise = ( rand( 1, N ) - 0.5 ) * NoiseAmp;

% Sygnał z szumem
noisySignal = sampledSignal + noise;

%% Widmo dla N N/5, N/25 i N/625
figure;
for noOfSmpsDiv = 1:4
    % Wyznaczenie mniejszefgo N
    Ndiv = N / ( 5 ^ ( 4 - noOfSmpsDiv ));
    
    % Normalizacja częstotliwości
    Fbase = Fsmp / Ndiv;
    sampledFreq = 0:Fbase:(Ndiv-1)*Fbase;
    
    % Wykres przebiegu czasowego
    subplot( 2, 4, noOfSmpsDiv );
    plot( sampledTime( 1:Ndiv ), noisySignal( 1:Ndiv ), 'b-');
    title( sprintf( "N = %d\n", Ndiv ));
    xlim([ 0 sampledTime( Ndiv ) ]);
    grid on; hold on;
    plot( sampledTime( 1:Ndiv ), sampledSignal( 1:Ndiv ),'r-');   
    
    % Wykres widma amplitudowego
    subplot( 2, 4, noOfSmpsDiv+4); 
    plot( sampledFreq, abs( fft( noisySignal( 1:Ndiv ))) );
    xlim([0 Fsmp/2 ]);  
end

