clear; clc; close all;

filterOrder = 400;
cutoffFreq = 0.2;

window = blackman(filterOrder + 1);

sampleIdx = 0:filterOrder;

impulseResponse = fir1(filterOrder, cutoffFreq, 'high', window);

zeroPadding = 1e5;

spectrum = abs(fft(impulseResponse, zeroPadding));
spectrumIdx = 0:zeroPadding-1;

fs = 1e6;
nyquistFreq = fs/2;

frequencies = spectrumIdx * nyquistFreq / (zeroPadding-1);

figure;
plot(frequencies, spectrum);
title('Funkcja przenoszenia - skala liniowa (filterOrder = 400)');
xlabel('Częstotliwość (Hz)');
ylabel('Amplituda');
ylim([-0.2 1.2]);
grid on;