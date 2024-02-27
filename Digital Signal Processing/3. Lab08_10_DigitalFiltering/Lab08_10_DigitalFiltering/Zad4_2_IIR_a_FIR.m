%% Porówanie filtrów 
clear; clc; close all;

%% Parametry filtru
IIRfilterOrder = 4;             % Rząd filtru IIR
FIRfilterOrder = 16;             % Rząd filtru FIR
Fsmp = 1000;                    % Częstotliwość próbkowania [Hz]
cutoffFreq = 100;               % Częstotliwość graniczna [Hz]

FNyq = Fsmp / 2;                % Częstotliwość Nyquista

%% Definicja filtru IIR
% Filtr Butterworth'a, dolnoprzepustowy, rzędu filterOrder o częstotliwości
% granicznej unormowanej do częstotliwości Nyquista
[ b, a ] = butter( IIRfilterOrder, cutoffFreq / FNyq );

% Odpowiednik analogowy - używamy tej samej funkcji, tylko z parametrem 's'
% co obliczy współczynniki filtru analogowego.
% Częstotliwość graniczną podajemy w tym przypadku w rad/s
[ bs, as ] = butter( IIRfilterOrder, 2 * pi * cutoffFreq, 's' );

%% Definicja filtru FIR
b_fir = fir1( FIRfilterOrder, cutoffFreq / FNyq, 'low', blackman( FIRfilterOrder + 1 ) );

%% Chrakterystyka częstotliwościowa
% Wykres tworzony "ręczne" tak, aby zapewnić tą samą skalę osi OX i OY
% Zamiast rysować wykresy funkcjami wbudowanymi, pobieramy zwracane przez
% nie dane:
% Dla filtru IIR: wektor wartości funkcji przenosznia, wektor częstości
% wyrazony w rad/sample
[ hz, wz ] = freqz( b, a );

% Przeliczamy rad/sample na Hz:
fz = ( wz ./ pi ) .* FNyq;

% Dla filtru FIR: wektor wartości funkcji przenosznia, wektor częstości
% wyrazony w rad/sample
[ hz_fir, wz_fir ] = freqz( b_fir );

% Przeliczamy rad/sample na Hz:
fz_fir = ( wz_fir ./ pi ) .* FNyq;

% Dla filtru analogowego: wektor wartości funkcji przenosznia, wektor 
% częstości w rad/s
[ hs, ws ] = freqs( bs, as );

% Przeliczamy rad/s na Hz:
fs = ws ./ ( 2 * pi );

% Wykres funkcji przenoszenia
figure( 1 ), semilogx( fs, 20*log10( abs( hs ) ) );
hold on;
semilogx( fz, 20*log10( abs( hz ) ) );
semilogx( fz_fir, 20*log10( abs( hz_fir ) ) );
grid on;

legend( "Filtr analogowy", "Filtr cyfrowy IIR", "Filtr cyfrowy FIR")

xlim( [ 10 1000 ] );
ylim( [ -60 1 ] );

%% Odpowiedź impulsowa
figure( 2 ), impz( b, a ), title( "Odpowiedź impulsowa IIR ");
figure( 3 ), impz( b_fir ), title( "Odpowiedź impulsowa FIR ");
grid on;

% Długość odpowiedzi impulsowej
len = impzlength( b, a );
fprintf( 'Długość odpowiedzi impulsowej IIR = %d [próbki]\n', len );
len_fir = impzlength( b_fir );
fprintf( 'Długość odpowiedzi impulsowej FIR = %d [próbki]\n', len_fir );

