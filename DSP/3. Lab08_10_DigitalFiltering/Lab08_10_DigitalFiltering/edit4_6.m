clear; clc; close all;

%% Parametry filtru
freqs = [0  0.1  0.2  0.3  0.4  0.5  0.6  0.7  0.8  1];
gains = [0  0    5    1    0    0    1    5    0  0];

%% Obliczenie filtru metodą Yule-Walker'a
filterOrder = length(freqs) * 6;
[b, a] = yulewalk(filterOrder, freqs, gains);

%% Wykresy - funkcja przenoszenia, bieguny i zera
figure, plot(freqs, gains);
hold on;
grid on;

[hz, wz] = freqz(b, a);
fz = wz ./ pi;

plot(fz, abs(hz));
legend("Zadana funkcja", "Filtr IIR");

xlabel('Częstotliwość [Hz]');
ylabel('Amplituda');
title('Funkcja przenoszenia filtru');

figure, zplane(b, a);
xlabel('Część rzeczywista');
ylabel('Część urojona');
title('Diagram biegunów i zer filtru');

figure, impz(b, a);
xlabel('Indeks próbki');
ylabel('Amplituda');
title('Odpowiedź impulsowa filtru');