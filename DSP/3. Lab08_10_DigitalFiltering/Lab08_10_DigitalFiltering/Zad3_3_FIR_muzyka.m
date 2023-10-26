%% Zastosowanie prostych filtrów FIR do filtracji muzyki
clear; clc; close all;

%% Definicja filtru
filterOrder = 50;           % Rząd filtru
cutoffFreq = 0.5;           % Częstotliwość graniczna wyrażona jako ułamek
                            % częstotliwości Nyquista ( 0 - 1.0 )

% Definicja funkcji okna filtru:
% rectwin - okno prostokątne (jak w poprzednich zadniach)
% blackman
% hamming
% hanning
window = rectwin( filterOrder + 1 );

% Odpowiedź impulsową, czyli współczynniki filtru (!) wyznaczamy z użyciem 
% wbudowanej funkcji fir1. Argumenty:
% * rząd filtru
% * częstotlwiosć graniczna wyrażona jako ułamek częstotliwości Nyquista
% * typ filtru: 
%     low = dolnoprzepustowy, 
%     high = górnoprzepustowy, 
%     bandpass = pasmowo-przepustowy
%     stop = pasmowo-zaporowy
% * okno filtru
% Dokumentacja: https://uk.mathworks.com/help/signal/ref/fir1.html


%% Wczytanie pliku i filtracja
[ samples, Fsmp ] = audioread( "media/2L-092_01_44kHz_32b.mp3" );
fg = 1000 
f = fg/(Fsmp/2)
cutoffFreq = f
FIRcoefs = fir1( filterOrder, cutoffFreq, 'low', window );

filteredSamples = filter( FIRcoefs, 1, samples );

%% Widmo sygnału przed i po filtracji
% Kod (komentarze) -- skrypt Zad7_2_muzyka_filtracja z tematu DFT)
N = length( samples );
Fbase = Fsmp / N;
frequencies = 0:Fbase:(N-1)*Fbase;
spectrum = fft( samples );
figure, subplot(1, 2, 1), semilogy( frequencies, abs( spectrum( :, 1 ) ) ), title( "Widmo amplitudowe - kanał L" );
xlim( [0 Fsmp/2] );
grid on;
subplot(1, 2, 2), semilogy( frequencies, abs( spectrum( :, 2 ) ) ), title( "Widmo amplitudowe - kanał R" );
xlim( [0 Fsmp/2] );
grid on;

filteredSpectrum = fft( filteredSamples );
figure, subplot(1, 2, 1), semilogy( frequencies, abs( filteredSpectrum( :, 1 ) ) ), title( "Widmo amplitudowe po filtracji - kanał L" );
xlim( [0 Fsmp/2] );
grid on;
subplot(1, 2, 2), semilogy( frequencies, abs( filteredSpectrum( :, 2 ) ) ), title( "Widmo amplitudowe po filtracji - kanał R" );
xlim( [0 Fsmp/2] );
grid on;

%% Odtwarzanie - oryginał i po filtracji

PlaySound( samples, Fsmp );
PlaySound( filteredSamples, Fsmp );

