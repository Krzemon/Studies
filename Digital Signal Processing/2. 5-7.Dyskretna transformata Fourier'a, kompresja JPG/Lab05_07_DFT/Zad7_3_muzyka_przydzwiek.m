%% Transformata odwrotna - filtracja przydżwięku sieciowego
clear; clc; close all; dbclear all;
dbstop in dbStop;

%% Paramatry filtracji
filterWidth = 200;           % Szerokość filtru w próbkach
includeEvenHarm = 1;        % Filtracja parzystych harmonicznych (1 - włączona, 0 - wyłączona)

%% Wczytanie pliku i wizualizacja widma
[ samplesHum, Fsmp ] = audioread( "media/2L-092_01_44kHz_32b_50Hz_hum.mp3" );
% [ samplesHum, Fsmp ] = audioread( "media/2L-092_01_44kHz_32b_50Hz_hum_real.mp3" );
samplesClean = audioread( "media/2L-092_01_44kHz_32b.mp3" );

N = length( samplesHum );
Fbase = Fsmp / N;

frequencies = 0:Fbase:(N-1)*Fbase;

% Plik jest stereo, więc ma dwa osobne kanały (prawy i lewy) - dwa ciągi
% próbek, a więc i dwa widma
% Obliczamy widmo sygnału z i bez szumu
spectrumHum = fft( samplesHum );
spectrumClean = fft( samplesClean );

% Widmo oryginlanego sygnału
figure, subplot(4, 2, 1), semilogx( frequencies, abs( spectrumHum( :, 1 ) ) ), title( "Widmo amplitudowe - kanał L" );
xlim( [0 Fsmp/2] );
grid on;
subplot(4, 2, 2), semilogx( frequencies, abs( spectrumHum( :, 2 ) ) ), title( "Widmo amplitudowe - kanał R" );
xlim( [0 Fsmp/2] );
grid on;

subplot(4, 2, 3), semilogx( frequencies, abs( spectrumHum( :, 1 ) - spectrumClean( :, 1 ) ) ), title( "Różnica widm (czysty sygnał) - kanał L" );
xlim( [0 Fsmp/2] );
grid on;
subplot(4, 2, 4), semilogx( frequencies, abs( spectrumHum( :, 2 ) - spectrumClean( :, 2 ) ) ), title( "Różnica widm (czysty sygnał) - kanał R" );
xlim( [0 Fsmp/2] );
grid on;

%% Odtwarzanie oryginalnego pliku
PlaySound( samplesHum, Fsmp );

dbStop();

%% Usunięcie 50Hz
kHum = round( 50 / Fbase ) + 1;         % Numer prążka odpowiadający 50 Hz

% Wyzerowanie -/+filterWidth próbek wokół 50 Hz
spectrumFiltered = spectrumHum;
spectrumFiltered( kHum-filterWidth/2:kHum+filterWidth/2, : ) = complex( zeros( filterWidth+1, 2 ) );
spectrumFiltered( N-(kHum+filterWidth/2):N-(kHum-filterWidth/2), : ) = complex( zeros( filterWidth+1, 2 ) );

%% Wizualizacja widma po filtracji

subplot(4, 2, 5), semilogx( frequencies, abs( spectrumFiltered( :, 1 ) - spectrumClean( :, 1 ) ) ), title( "Różnica widm po filtracji - kanał L" );
xlim( [0 Fsmp/2] );
grid on;
subplot(4, 2, 6), semilogx( frequencies, abs( spectrumFiltered( :, 2 ) - spectrumClean( :, 2 ) ) ), title( "Różnica widm po filtracji - kanał R" );
xlim( [0 Fsmp/2] );
grid on;

%% Transformata odwrotna i odtworzenie dżwięku
samplesFiltered = real( ifft( spectrumFiltered ) );

PlaySound( samplesFiltered, Fsmp );

dbStop();

%% Usunięcie 50Hz i jego harmonicznych

spectrumFilteredHarm = spectrumHum;

for fHum = 50:(50 + 50*(1-includeEvenHarm)):Fsmp/2
    kHum = round( fHum / Fbase ) + 1;

    spectrumFilteredHarm( kHum-filterWidth/2:kHum+filterWidth/2, : ) = complex( zeros( filterWidth+1, 2 ) );
    spectrumFilteredHarm( N-(kHum+filterWidth/2):N-(kHum-filterWidth/2), : ) = complex( zeros( filterWidth+1, 2 ) );
end

%% Wizualizacja widma po filtracji
subplot(4, 2, 7), semilogx( frequencies, abs( spectrumFilteredHarm( :, 1 ) ) ), title( "Różnica widm po filtracji harmonicznych- kanał L" );
xlim( [0 Fsmp/2] );
grid on;
subplot(4, 2, 8), semilogx( frequencies, abs( spectrumFilteredHarm( :, 2 ) ) ), title( "Różnica widm po filtracji harmonicznych - kanał R" );
xlim( [0 Fsmp/2] );
grid on;

%% Transformata odwrotna i odtworzenie dżwięku
samplesFilteredHarm = real( ifft( spectrumFilteredHarm ) );

PlaySound( samplesFilteredHarm, Fsmp );


%% Pusta funkcja pełniąca rolę pułapki zatrzymującej symulację.
function [] = dbStop()
end