%% Porównanie filtrów IIR
clear; clc; close all;

%% Parametry filtru
filterOrder = 4;                % Rząd filtru
Fsmp = 1000;                    % Częstotliwość próbkowania [Hz]
cutoffFreq = 100;               % Częstotliwość graniczna [Hz]

FNyq = Fsmp / 2;                % Częstotliwość Nyquista

%% Definicja filtrów
% Filtr Butterworth'a
[ b_butter, a_butter ] = butter( filterOrder, cutoffFreq / FNyq );

% Chebyshev typu I - 3 dB falowania w paśmie przenoszenia
[ b_cheby1, a_cheby1 ] = cheby1( filterOrder, 3, cutoffFreq / FNyq );

% Chebyshev typu II - 30 dB tłumienia w paśmie zaporowym
[ b_cheby2, a_cheby2 ] = cheby2( filterOrder, 30, cutoffFreq / FNyq );

% Filtr eliptyczny - 3 dB falowania w paśmie przenoszenia i 30 dB 
% tłumienia w paśmie zaporowym.
[ b_ellip, a_ellip ] = ellip( filterOrder, 3, 30, cutoffFreq / FNyq );

%% Chrakterystyki częstotliwościowe
[ h_butter, w_butter ] = freqz( b_butter, a_butter );
f_butter = ( w_butter ./ pi ) .* FNyq;

[ h_cheby1, w_cheby1 ] = freqz( b_cheby1, a_cheby1 );
f_cheby1 = ( w_cheby1 ./ pi ) .* FNyq;

[ h_cheby2, w_cheby2 ] = freqz( b_cheby2, a_cheby2 );
f_cheby2 = ( w_cheby2 ./ pi ) .* FNyq;

[ h_ellip, w_ellip ] = freqz( b_ellip, a_ellip );
f_ellip = ( w_ellip ./ pi ) .* FNyq;

figure( 11 ), semilogx( f_butter, 20*log10( abs( h_butter ) ) );
hold on;
grid on;
semilogx( f_cheby1, 20*log10( abs( h_cheby1 ) ) );
semilogx( f_cheby2, 20*log10( abs( h_cheby2 ) ) );
semilogx( f_ellip, 20*log10( abs( h_ellip ) ) );

legend( "Butterworth", "Chebyshev I", "Chebyshev II", "Eliptyczny", 'Location','southwest' );

% xlim( [10 1000 ] );
ylim( [ -100 10 ] );

%% Bieguny i zera
figure, zplane( b_butter, a_butter ), title( "Butterworth");
figure, zplane( b_cheby1, a_cheby1 ), title( "Chebyshev I");
figure, zplane( b_cheby2, a_cheby2 ), title( "Chebyshev II");
figure, zplane( b_ellip, a_ellip ), title( "Eliptyczny");

