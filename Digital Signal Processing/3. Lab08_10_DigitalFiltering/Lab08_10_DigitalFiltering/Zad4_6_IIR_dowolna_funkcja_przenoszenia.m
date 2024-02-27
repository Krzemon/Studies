%% Projektowanie filtrów IIR o dowolnej charakterystyce przenoszenia
clear; clc; close all;

%% Parametry filtru

% Projektujemy zestaw par punktów: częstotliwość - wzmocnienie.
% Punkty zapisujemy w dwóch wektorach - jeden reprezentuje częstotliwości,
% drugi - odpowiadające im wzmocnienia.
% Częstotliwości podajemy unormowane do częstotliwości Nyquista


%do raportu dowolna charakteerystyka (tylko nie plaska) do zbadania
%yulewalkerem


freqs = [ 0  0.1  0.2  0.3  0.4  0.5  0.6  0.7  0.8  1 ];
gains = [ 0    0    1    1    0    0    1    1    0  0 ];

%% Obliczenie filtru metodą Yule-Walker'a

%filterOrder = length( freqs );
filterOrder = 100;
[ b, a ] = yulewalk( filterOrder, freqs, gains );

%% Wykresy - funkcja przenoszenia, bieguny i zera

figure, plot( freqs, gains );
hold on;
grid on;

[ hz, wz ] = freqz( b, a );
fz = wz ./ pi;

plot( fz, abs( hz ) );
legend( "Zadana funkcja", "Filtr IIR" );

figure, zplane( b, a );
figure, impz( b, a );
