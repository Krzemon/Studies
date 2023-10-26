clear; clc; close all;

%% Definicja filtru
filterOrder = 50;           % Rząd filtru
cutoffFreq1 = 0.1;          % Częstotliwość graniczna 1 dla filtru pasmowo-zaporowego
cutoffFreq2 = 0.3;          % Częstotliwość graniczna 2 dla filtru pasmowo-zaporowego

%% Wyznaczanie współczynników filtrów
impulseResponse_bandstop = fir1(filterOrder, [cutoffFreq1, cutoffFreq2], 'stop');
impulseResponse_lowpass = fir1(filterOrder, cutoffFreq1, 'low');
impulseResponse_highpass = fir1(filterOrder, cutoffFreq2, 'high');

%% Odbicie filtrów w osi x (odwrócenie fazowe)
impulseResponse_lowpass_flipped = -impulseResponse_lowpass;
impulseResponse_highpass_flipped = -impulseResponse_highpass;

%% Obliczanie sumy odbitych filtrów
impulseResponse_sum = impulseResponse_lowpass_flipped + impulseResponse_highpass_flipped;

%% Generowanie wykresu
sampleIdx = 0:filterOrder;

figure;
stem(sampleIdx, impulseResponse_bandstop, 'b-', 'LineWidth', 1.5);
hold on;
stem(sampleIdx, impulseResponse_sum, 'r-', 'LineWidth', 1.5);
hold off;
title('Współczynniki filtru pasmowo-zaporowego i suma odbitych filtrów');
legend('Filtr pasmowo-zaporowy', 'Suma odbitych filtrów');
grid on;
xlabel('Indeks próbki');
ylabel('Współczynniki filtru');