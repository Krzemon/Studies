%% Podstawy filtrów IIR
clear; clc; close all;

%% Parametry filtru
filterOrder = 4;                % Rząd filtru
Fsmp = 1000;                    % Częstotliwość próbkowania [Hz]
cutoffFreq = 1;               % Częstotliwość graniczna [Hz]

FNyq = Fsmp / 2;                % Częstotliwość Nyquista

%% Definicja filtru
% Filtr Butterworth'a, dolnoprzepustowy, rzędu filterOrder o częstotliwości
% granicznej unormowanej do częstotliwości Nyquista
[ b, a ] = butter( filterOrder, cutoffFreq / FNyq );

% Odpowiednik analogowy - używamy tej samej funkcji, tylko z parametrem 's'
% co obliczy współczynniki filtru analogowego.
% Częstotliwość graniczną podajemy w tym przypadku w rad/s
[ bs, as ] = butter( filterOrder, 2 * pi * cutoffFreq, 's' );

%% Chrakterystyka częstotliwościowa
% Z użyciem wbudowanych funkcji Matlab'a:
% Filrt IIR
figure( 1 ), freqz( b, a ), title( "Filtr IIR" );
% Filtr analogowy
figure( 2 ), freqs( b, a ), title( "Filtr analogowy" );

% Wykres tworzony "ręczne" tak, aby zapewnić tą samą skalę osi OX i OY
% Zamiast rysować wykresy funkcjami wbudowanymi, pobieramy zwracane przez
% nie dane:

% Dla filtru IIR: wektor wartości funkcji przenosznia, wektor częstości
% wyrazony w rad/sample
[ hz, wz ] = freqz( b, a );

% Przeliczamy rad/sample na Hz:
fz = ( wz ./ pi ) .* FNyq;

% Dla filtru analogowego: wektor wartości funkcji przenosznia, wektor 
% częstości w rad/s
[ hs, ws ] = freqs( bs, as );
% Przeliczamy rad/s na Hz
fs = ws ./ ( 2 * pi );

% Wykres funkcji przenoszenia
figure( 3 ), semilogx( fs, 20*log10( abs( hs ) ) );
hold on;
semilogx( fz, 20*log10( abs( hz ) ) );

grid on;

legend( "Filtr analogowy", "Filtr cyfrowy IIR", 'Location','southwest' );

% Ograniczenie osi OX: 0 - 1000 Hz
xlim( [ 0 1000 ] );
% Ogranicznie osi OY: -60 - 1 dB
ylim( [ -60 1 ] );
title("Charakterystyka przenoszenia (zoom)")
ylabel("Magnitude")
xlabel("Frequency (rad/s)")

%% Bieguny i zera
figure( 4 ), zplane( b, a );

%% Odpowiedź impulsowa
figure( 5 ), impz( b, a );
grid on;

% Długość odpowiedzi impulsowej
len = impzlength( b, a );
fprintf( 'Długość odpowiedzi impulsowej = %d [próbki]\n', len );


