%% Projektowanie filtrów FIR
clear; clc; close all;

%% Definicja filtru
N = 31;                  % Rząd filtru (liczba współczynników)
K = 7;                   % Ilość jedynek (szerokość impulsu prostokątnego)
lowerFreq = 0.2;         % Dolna częstotliwość graniczna pasma przenoszenia
upperFreq = 0.4;         % Górna częstotliwość graniczna pasma przenoszenia

% Tworzymy filtr - impuls szerokości K symetrycznie otoczony zerami
zerosBefore = floor((N - K) / 2);
zerosAfter = ceil((N - K) / 2);

requestedH = [zeros(1, zerosBefore), ones(1, K), zeros(1, zerosAfter)];

%% Wykres zadanej funkcji przenoszenia
indexesSym = [-ceil(N/2) + 1 : floor(N/2)];

figure, stem(indexesSym, requestedH);
title('Zadana funkcja przenoszenia (Filtr pasmowo-przepustowy)');
xlabel('Indeks');
ylabel('Amplituda');
xlim([-ceil(N/2) + 1  floor(N/2)]);

%% Obliczenie współczynników filtru

% Obliczanie transformaty odwrotnej DFT
timeResponse = ifftshift(ifft(requestedH));

indexes = 0 : N-1;

figure, stem(indexes, timeResponse);
title('Współczynniki filtru');
xlabel('Indeks');
ylabel('Amplituda');
xlim([0, N-1]);

%% Spectral Reversal
shiftedHlp = timeResponse; % Skopiowanie przesuniętych współczynników

% Obliczenie indeksów granicznych pasma przenoszenia
lowerIdx = round(lowerFreq * N); % Dolny indeks pasma przenoszenia
upperIdx = round(upperFreq * N); % Górny indeks pasma przenoszenia

% Tworzenie filtru pasmowo-przepustowego poprzez mnożenie przez sinus
shiftedHbp = shiftedHlp;
shiftedHbp(lowerIdx:upperIdx) = shiftedHlp(lowerIdx:upperIdx) .* sin(pi * (lowerIdx:upperIdx));

% Przesunięcie wartości odwrotnych w pasmie zaporowym
shiftedHbp(1:lowerIdx-1) = -shiftedHlp(1:lowerIdx-1);
shiftedHbp(upperIdx+1:end) = -shiftedHlp(upperIdx+1:end);

% Przesunięcie z powrotem do pierwotnej konfiguracji
shiftedHbp = circshift(shiftedHbp, -floor(N/2));

%% Obliczenie i wykres rzeczywistej funkcji przenoszenia
% Obliczamy transformatę DFT wraz z zero padding = 1000
realHbp = fftshift(fft(shiftedHbp, 1000));
spectrumIdx = 0 : length(realHbp) - 1;

figure, plot(spectrumIdx, abs(realHbp));
title('Rzeczywista funkcja przenoszenia (Filtr pasmowo-przepustowy)');
xlabel('Indeks częstotliwości');
ylabel('Amplituda');