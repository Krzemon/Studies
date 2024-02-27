%% Podstawy filtrów IIR
clear; clc; close all;

%% Parametry filtru
filterOrder = 16;                % Rząd filtru
Fsmp = 1000;                    % Częstotliwość próbkowania [Hz]
cutoffFreq = 100;               % Częstotliwość graniczna [Hz]

FNyq = Fsmp / 2;                % Częstotliwość Nyquista

%% Definicja filtru
% Filtr Butterworth'a, dolnoprzepustowy, rzędu filterOrder o częstotliwości
% granicznej unormowanej do częstotliwości Nyquista
[ b, a ] = butter( filterOrder, cutoffFreq / FNyq );

% Odpowiednik analogowy - używamy tej samej funkcji, tylko z parametrem 's'
% co obliczy współczynniki filtru analogowego.
% Częstotliwość graniczną podajemy w tym przypadku w rad/s
[ bs, as ] = butter( filterOrder, 2 * pi * cutoffFreq, 's' );

% Mając odpowiednik analogowy, możemy obliczyć filtr IIR metodą
% transformaty biliniowej
[ b_bilinear, a_bilinear ] = bilinear( bs, as, Fsmp );

% Oraz metodą niezmienniczości odpowiedzi impulsowej
[ b_impinvar ,a_impinvar ] = impinvar( bs, as, Fsmp );

%% Chrakterystyka częstotliwościowa
% Dla filtru IIR: wektor wartości funkcji przenosznia, wektor częstości
% wyrazony w rad/sample
[ hz, wz ] = freqz( b, a );

% Przeliczamy rad/sample na Hz:
fz = ( wz ./ pi ) .* FNyq;

% Dla IIR z transformaty biliniowej
[ h_bilin, w_bilin ] = freqz( b_bilinear, a_bilinear );
f_bilin = ( w_bilin ./ pi ) .* FNyq;

% Dla IIR z niezmienniczości odpowiedzi impulsowej
[ h_impinvar, w_impinvar ] = freqz( b_impinvar, a_impinvar );
f_impinvar = ( w_impinvar ./ pi ) .* FNyq;


% Wykres funkcji przenoszenia
figure( 1 ), semilogx( fz, 20*log10( abs( hz ) ) );
hold on;
semilogx( f_bilin, 20*log10( abs( h_bilin ) ) );
semilogx( f_impinvar, 20*log10( abs( h_impinvar ) ) );

grid on;

legend( "IIR Matlab", "IIR - metoda biliniowa", "IIR - metoda niezmienniczości odpowiedzi impulsowej", 'Location','southwest' );

% Ograniczenie osi OX: 0 - 1000 Hz
xlim( [ 0 1000 ] );
% Ogranicznie osi OY: -60 - 1 dB
%ylim( [ -60 1 ] );

%% Bieguny i zera
figure( 2 ), zplane( b, a ), title( "IIR Matlab" );
figure( 3 ), zplane( b_bilinear, a_bilinear ), title( "IIR - metoda biliniowa" );
figure( 4 ), zplane( b_impinvar, a_impinvar ), title( "IIR - metoda niezmienniczości odpowiedzi impulsowej" );


