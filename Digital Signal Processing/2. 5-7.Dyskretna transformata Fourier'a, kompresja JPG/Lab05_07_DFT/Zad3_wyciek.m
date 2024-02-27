%% Wyciek widma
clear; clc; close all; dbclear all;
% Zatrzymanie symulacji przy wywołaniu funkcji dbStop - pusta funkcja
% pełniąca rolę pułapki zatrzymującej symulację.
dbstop in dbStop;


%% Parametry próbkowania
Fsmp = 16000;       % Częstotliwość próbkowania [Hz]
N = 16;             % Ilość próbek

%% Parametry sygnału
Fsig = 2500;        % Częstotliwość sygnału [Hz]

%% Generacja sygnału i wykres przebiegu czasowego
Tsmp = 1 / Fsmp;    % Okres próbkowania [s]

sampledTime = 0:Tsmp:(N-1)*Tsmp;                                            % Wektor skwantowanego czasu
sampledSignal = sin( 2*pi * Fsig * sampledTime );     % Wektor wartości próbek sygnału

figure(1), subplot(3,3,1), plot(sampledTime, sampledSignal, 'bx--'), title( 'Ciąg próbek w czasie' );
grid on;

%% Obliczenie widma - DFT
spectrum = fft( sampledSignal );    % Obliczamy DFT używając algorytmu FFT

%% Widmo amplitudowe
amplitude = abs( spectrum );        % Nieznormalizowana wartość amplitudy

Fbase = 1;                          % Częstotliwość bazowa - DO UZUPEŁNIENIA

sampledFreq = 0:Fbase:(N-1)*Fbase;  % Wektor skwantowanych częstotliwości

subplot(3,3,4),  stem( sampledFreq, amplitude ), title( 'Widmo amplitudowe' );
xlim( [ 0 N ]);
xticks( 0:1:N );
grid on;

%% Faza
% Usunięcie błędów precyzji obliczeniowej: ustawiamy dokładnie zero tam,
% gdzie amplituda widma jest mniejsza od 10^(-6)

spectrum( abs(spectrum) < 1e-6 ) = complex( 0 );

subplot(3, 3, 7), stem( sampledFreq, angle( spectrum ) ./ pi ), title( 'Faza' );
xlim( [ 0 N ]);
xticks( 0:1:N );

grid on;

dbStop();

%% Hipoteza - transformata (prawie) nieskończonenie długiego sygnału oryginalnego
% Generacja sygnału i wykres w czasie
continousTime = (-500*N*Tsmp):Tsmp:(500*N*Tsmp - Tsmp);
continousSignal = sin( 2*pi * Fsig * continousTime ); 

subplot(3,3,2), plot(continousTime, continousSignal, 'bx--'), title( 'Błędna postać sygnału quazi-ciągłego w czasie' );
xlim( [ -2*N*Tsmp 3*N*Tsmp] );
grid on;

% Widmo amplitudowe sygnału
FbaseCont = Fbase / 1000;
continousFreq = 0:FbaseCont:(1000*N-1)*FbaseCont;

continousSpectrum = fft( continousSignal );
continousAmplitude = abs( continousSpectrum );        % Nieznormalizowana wartość amplitudy
subplot(3,3,5),  stem( continousFreq, continousAmplitude ), title( 'Widmo amplitudowe' );
xlim( [ 0 N ]);
xticks( 0:1:N );
grid on; hold on;
plot( continousFreq(1:1000:end), continousAmplitude(1:1000:end), 'rs', 'MarkerSize', 12 );
hold off;

% Faza sygnału
continousSpectrum( abs(continousSpectrum) < 1e-6 ) = complex( 0 );
subplot(3, 3, 8), stem( continousFreq, angle( continousSpectrum ) ./ pi ), title( 'Faza' );
xlim( [ 0 N ]);
xticks( 0:1:N );

grid on;

dbStop();
    
%% Rzeczywistość - transformata (prawie) nieskończonenie długiego sygnału oryginalnego obłożonego oknem prostokątnym
    
% Generacja sygnału i wykres w czasie
realSignal = [ zeros(1,500*N ) sampledSignal zeros(1, 500*N - N) ];

subplot(3,3,3), plot(continousTime, realSignal, 'bx--'), title( 'Prawdziwa postać sygnału quazi-ciągłego w czasie' );
xlim( [ -2*N*Tsmp 3*N*Tsmp] );
grid on; hold on;

rectWindow = [ zeros(1,500*N ) ones( 1, N) zeros(1, 500*N - N) ];
plot( continousTime, rectWindow, 'k' );
legend( "Sygnał obłożony okem", "Okno prostokątne" );
    
% Widmo amplitudowe sygnału
realSpectrum = fft( realSignal );
realAmplitude = abs( realSpectrum );        % Nieznormalizowana wartość amplitudy
subplot(3,3,6),  plot( continousFreq, realAmplitude ), title( 'Widmo amplitudowe' );
xlim( [ 0 N ]);
xticks( 0:1:N );
grid on; hold on;
plot( continousFreq(1:1000:end), realAmplitude(1:1000:end), 'rs', 'MarkerSize', 12 );
hold off;

% Faza sygnału
realSpectrum( abs(realSpectrum) < 1e-6 ) = complex( 0 );
subplot(3, 3, 9), plot( continousFreq, angle( realSpectrum ) ./ pi ), title( 'Faza' );
xlim( [ 0 N ]);
xticks( 0:1:N );
grid on;
    
% Dodanie prawidłowego widma quazi-ciągłego do wykresu widma ciągu próbek
subplot( 3, 3, 4); hold on;
plot( continousFreq, realAmplitude, 'k' )

%% Pusta funkcja pełniąca rolę pułapki zatrzymującej symulację.
function [] = dbStop()
end