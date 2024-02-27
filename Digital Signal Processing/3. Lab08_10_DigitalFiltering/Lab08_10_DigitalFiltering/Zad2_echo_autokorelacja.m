%% Echo - dodawanie i analiza (funckja autokorelacji)
clear; clc; close all;


%% Parametry echa
delay = 0.2;        % Opóźnienie wyrażone w [s]
gain = 1;         % Wzmocnienie echa (UWAGA: nie przekraczać 1 dla dobra własnych uszu!)


%% Wczytanie dźwięku

% 9 second sample of the Hallelujah chorus from Handel's Messiah
load handel;
Fsmp = Fs;
samples = y;

[ samples, Fsmp ] = audioread( "media/pianino_A4.mp3" );
% [ samples, Fsmp ] = audioread( "media/2L-092_01_44kHz_32b.mp3" );

% Przerabiamy próbki na mono jeśli są stereo biorąc jeden z kanałów.
samples = samples( :, 1 );

%% Generacja echa
Tsmp = 1/Fsmp;                              % Okres próbkowania
samplesDelay = round( delay / Tsmp );       % Opóźnienie wyrażone w ilości próbek

% Wektor próbek opóżnionych (przesuniętych w czasie w przód) o samplesDelay
% próbek i pomnożonych przez gain (wzmocnienie)
delayedSamples = gain .* [ zeros( samplesDelay, 1 ); samples( 1 : end - samplesDelay, : ) ];

% Generacja echa - suma oryginalnych próbek oraz przesuniętych w czasie 
echoSamples = samples + delayedSamples;

filterCoefs = [ 1 zeros(1, samplesDelay-1) gain ];
echoSamples = filter( filterCoefs, 1, samples );


% Renormalizacja
max( samples ) / max( echoSamples )
echoSamples = echoSamples .* ( max( samples ) / max( echoSamples ) );
%jesli w zad 4_7 jest 1 jako b to trzeba tu zakomentowac
%% Wizualizacja dźwięku w czasie
sampledTime = 0 : Tsmp : ( length( samples) - 1 ) * Tsmp;       % Wektor czasu 

% Próbki orygnalne i opóźnione (echo)
figure(1), subplot(3,1,1);
plot( sampledTime, [ samples delayedSamples ] );
legend('Original','Echo');

% Suma próbek - dźwięk z dołożonym echem
subplot(3,1,2);
plot( sampledTime, echoSamples ), title( 'Suma sygnałów' );

%% Analiza echa - obliczenie funkcji autokorelacji
% Używamy funkcji xcorr. Liczy ona albo korelację dla dwóch wektorów, albo,
% jeśli podamy tylko jeden - jego autokorelację.
% Drugi z argumentów steruje normalizacją
% (https://uk.mathworks.com/help/signal/ug/correlation-and-covariance.html)
[ Rmm, lags ] = xcorr( echoSamples, 'coeff' );

% Wyświetlamy tylko korelację dla dodatnich czasów
Rmm = Rmm( lags > 0 );
lags = lags( lags > 0 );

% Wykres funkcji autokorelacji
subplot(3,1,3);
plot( lags/Fsmp, Rmm ), title( 'Funkcja autokorelacji' );

%% Odtworzenie dżwięku
PlaySound( samples, Fsmp );
PlaySound( echoSamples, Fsmp );
