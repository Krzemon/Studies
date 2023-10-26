%% Transformata odwrotna - filtracja muzyki
clear; clc; close all;

%% Paramatry filtru
filterType = 3;     % 1 - filtr dolnoprzepustowy
                    % 2 - filtr górnoprzepustowy
                    % 3 - filtr pasmowo-zaporowy

fLowCut = 1000;     % Częstotlwość graniczna filtru dolnoprzepustowego [Hz]
fHighPass = 500;    % Częstotlwość graniczna filtru górnoprzepustowego [Hz]

fBandCut = 160;     % Dolna częstotliwość graniczna filtru pasmowo-zaporowego [Hz]
fBandPass = 1000;   % Górna częstotliwość graniczna filtru pasmowo-zaporowego [Hz]

%% Wczytanie pliku i wizualizacja widma
[ samples, Fsmp ] = audioread( "media/2L-092_01_44kHz_32b.mp3" );

N = length( samples );
Fbase = Fsmp / N;

frequencies = 0:Fbase:(N-1)*Fbase;

% Plik jest stereo, więc ma dwa osobne kanały (prawy i lewy) - dwa ciągi
% próbek, a więc i dwa widma
spectrum = fft( samples );

% Maksymalna wartość (głośność) oryginalnego pliku - do renormalizacji
% próbek po filtracji
maxVal = max( samples( :, 1) );

% Widmo oryginlanego sygnału
figure, subplot(1, 2, 1), semilogy( frequencies, abs( spectrum( :, 1 ) ) ), title( "Widmo amplitudowe - kanał L" );
xlim( [0 Fsmp/2] );
grid on;
subplot(1, 2, 2), semilogy( frequencies, abs( spectrum( :, 2 ) ) ), title( "Widmo amplitudowe - kanał R" );
xlim( [0 Fsmp/2] );
grid on;

%% Odtwarzanie oryginalnego pliku
PlaySound( samples, Fsmp );

%% Filtracja

% Inicializacja widm (osobno dla prawego i lewego kanału)
filteredSpectrum = complex( zeros( N, 2 ) );

%% Filtr dolnoprzepustowy
if filterType == 1
    % Wyznaczenie indeksu prążka odpowiadającego częstotliwości granicznej
    cutIdx = round( fLowCut / Fbase );
    % Wycięcie widma
    filteredSpectrum( 1:cutIdx, : ) = spectrum( 1:cutIdx, : );
    filteredSpectrum( N-cutIdx:N, : ) = spectrum( N-cutIdx:N, : );
end

%% Filtr górnoprzepustowy
if filterType == 2
    % Wyznaczenie indeksu prążka odpowiadającego częstotliwości granicznej
    cutIdx = round( fHighPass / Fbase );
    % Wycięcie widma
    filteredSpectrum( cutIdx : N - cutIdx, : ) = spectrum( cutIdx : N - cutIdx, : );
end

%% Filtr pasmowo-zaporowy
if filterType == 3
    % Wyznaczenie indeksów prążków odpowiadającego częstotliwościom granicznym
    bw1Idx = round( fBandCut / Fbase );
    bw2Idx = round( fBandPass / Fbase );

    filteredSpectrum( 1:bw1Idx, : ) = spectrum( 1:bw1Idx, : );
    filteredSpectrum( bw2Idx:N-bw2Idx, : ) = spectrum( bw2Idx:N-bw2Idx, : );
    filteredSpectrum( N-bw1Idx:N, : ) = spectrum( N-bw1Idx:N, : );
end

%% Wizualizacja widma po filtracji
figure, subplot(1, 2, 1), semilogy( frequencies, abs( filteredSpectrum( :, 1 ) ) ), title( "Widmo amplitudowe - kanał L" );
xlim( [0 Fsmp/2] );
grid on;
subplot(1, 2, 2), semilogy( frequencies, abs( filteredSpectrum( :, 2 ) ) ), title( "Widmo amplitudowe - kanał R" );
xlim( [0 Fsmp/2] );
grid on;

%% Transformata odwrotna
filteredSamples = real( ifft( filteredSpectrum ) );

%% Odtwarzanie przefiltrowanego dźwięku
PlaySound( (maxVal / max( filteredSamples( :, 1) ))*filteredSamples, Fsmp );
