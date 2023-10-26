%clear; clc; close all;

%% Definicja filtru
filterOrder = 50;           % Rząd filtru
cutoffFreq = 0.2;           % Częstotliwość graniczna wyrażona jako ułamek
                            % częstotliwości Nyquista ( 0 - 1.0 )

% Definicja funkcji okna filtru:
% rectwin - okno prostokątne (jak w poprzednich zadaniach)
% blackman
% hamming
% hanning
window = blackman( filterOrder + 1 );
%window = AAA
%% Wykres funkcji okna
sampleIdx = 0:filterOrder;  % Wektor indeksów próbek

figure(1), subplot( 4, 1, 1 ); stem( sampleIdx, window,'bd-'); title( 'Funkcja okna' );
grid on;
xlabel('Indeks próbki');
ylabel('Amplituda');

%% Wyznacznie i wyświetlanie odpowiedzi impulsowej

% Odpowiedź impulsową, czyli współczynniki filtru (!) wyznaczamy z użyciem 
% wbudowanej funkcji fir1. Argumenty:
% * rząd filtru
% * częstotliwość graniczna wyrażona jako ułamek częstotliwości Nyquista
% * typ filtru: 
%     low = dolnoprzepustowy, 
%     high = górnoprzepustowy, 
%     bandpass = pasmowo-przepustowy
%     stop = pasmowo-zaporowy
% * okno filtru
% Dokumentacja: https://uk.mathworks.com/help/signal/ref/fir1.html
impulseResponse = fir1( filterOrder, cutoffFreq, 'high', window );

% Wykres odpowiedzi impulsowej
subplot(4,1,2); stem( sampleIdx, impulseResponse,'bd-'); 
title('Odpowiedź impulsowa = współczynniki filtru');
grid on;
xlabel('Indeks próbki');
ylabel('Amplituda');

%% Wyznacznie i wyświetlanie funkcji przenoszenia filtru

zeroPadding = 1e5;          % Dopełnienie zerami wag filtru dla DTFT

% Wyliczenie widma - nie musimy sami dokładać zer, funkcja fft zrobi to za
% nas w jednym kroku:
spectrum = abs( fft( impulseResponse, zeroPadding) );

spectrumIdx = [ 0:zeroPadding-1 ];  % Indeksy prążków - DO ZAMIANY NA CZĘSTOTLIWOŚCI!!!

% Wykresy widma w skali liniowej i logarytmicznej
subplot(4,1,3); plot( spectrumIdx, spectrum ); title( 'Funkcja przenoszenia - skala liniowa' )
ylim( [ -0.2 1.2 ] );
grid on;
xlabel('Częstotliwość [Hz]');
ylabel('Amplituda');

subplot(4,1,4); plot( spectrumIdx, 20*log10( spectrum ) ); title( 'Funkcja przenoszenia - skala logarytmiczna' )
grid on;
xlabel('Częstotliwość [Hz]');
ylabel('Amplituda [dB]');

% Obliczenie wzmocnienia w paśmie zaporowym
cutoffIdx = round(cutoffFreq * (zeroPadding-1) + 1);
stopbandSpectrum = spectrum(cutoffIdx:end);
[stopbandMinValue, stopbandMinIdx] = min(stopbandSpectrum);

stopbandAmplitude = stopbandMinValue / max(spectrum);

stopbandAmplitude_dB = 20 * log10(stopbandAmplitude);

disp(['Oszacowane wzmocnienie w paśmie zaporowym: ', num2str(stopbandAmplitude_dB), ' dB']);


% Generowanie wykresów współczynników filtrów górnoprzepustowego i dolnoprzepustowego oraz ich stosunek
%{
%% Wyznaczanie współczynników filtrów
impulseResponse_highpass = fir1(filterOrder, cutoffFreq, 'high');
impulseResponse_lowpass = fir1(filterOrder, cutoffFreq, 'low');

%% Generowanie wykresów
sampleIdx = 0:filterOrder;

figure;
subplot(2, 1, 1);
stem(sampleIdx, impulseResponse_highpass, 'bd-', 'LineWidth', 1.5);
hold on;
stem(sampleIdx, impulseResponse_lowpass, 'rd-', 'LineWidth', 1.5);
hold off;
title('Współczynniki filtrów górnoprzepustowego i dolnoprzepustowego');
legend('Filtr górnoprzepustowy', 'Filtr dolnoprzepustowy');
grid on;

subplot(2, 1, 2);
stem(sampleIdx, impulseResponse_highpass ./ impulseResponse_lowpass, 'kd-', 'LineWidth', 1.5);
title('Stosunek współczynników filtrów górnoprzepustowego do dolnoprzepustowego');
grid on;
%}