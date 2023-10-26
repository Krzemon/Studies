clear; clc; close all;

%% Definicja filtru dolnoprzepustowego
N = 31;                  % Rząd filtru (liczba współczynników)
K = 7;                   % Ilość jedynek (szerokość impulsu prostokątnego)

% Tworzymy filtr dolnoprzepustowy - impuls szerokości K symetrycznie otoczony zerami
zerosBefore = floor((N - K) / 2);
zerosAfter = ceil((N - K) / 2);

requestedH_lowpass = [zeros(1, zerosBefore) ones(1, K) zeros(1, zerosAfter)];

%% Wykres zadanej funkcji przenoszenia dolnoprzepustowego
indexesSym_lowpass = [-ceil(N/2)+1 : floor(N/2)];

figure, stem(indexesSym_lowpass, requestedH_lowpass);
title('Zadana funkcja przenoszenia dolnoprzepustowego');
xlim([-ceil(N/2)+1  floor(N/2)]);
xlabel('Indeks');
ylabel('Amplituda');

%% Zamiana filtru dolnoprzepustowego na górnoprzepustowy
requestedH_highpass = -requestedH_lowpass;   % Zmiana znaku współczynników

%% Wykres zadanej funkcji przenoszenia górnoprzepustowego
indexesSym_highpass = [-ceil(N/2)+1 : floor(N/2)];

figure, stem(indexesSym_highpass, requestedH_highpass);
title('Zadana funkcja przenoszenia górnoprzepustowego');
xlim([-ceil(N/2)+1  floor(N/2)]);
xlabel('Indeks');
ylabel('Amplituda');

%% Obliczenie współczynników filtru górnoprzepustowego

timeResponse_highpass = ifftshift(ifft(ifftshift(requestedH_highpass)));

indexes_highpass = 0 : N-1;

figure, stem(indexes_highpass, timeResponse_highpass);
title('Współczynniki filtru górnoprzepustowego');
xlim([0, N-1]);
xlabel('Indeks');
ylabel('Amplituda');

%% Obliczenie i wykres rzeczywistej funkcji przenoszenia górnoprzepustowego

realH_highpass = fftshift(fft(fftshift(timeResponse_highpass), 1000));
spectrumIdx_highpass = 0:length(realH_highpass) - 1;

figure, plot(spectrumIdx_highpass, abs(realH_highpass));
title('Rzeczywista funkcja przenoszenia górnoprzepustowego');
xlabel('Indeks częstotliwości');
ylabel('Amplituda');