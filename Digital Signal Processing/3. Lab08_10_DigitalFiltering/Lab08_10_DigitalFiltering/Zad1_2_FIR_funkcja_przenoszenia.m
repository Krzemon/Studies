%% Funkcja przenoszenia filtru FIR
clear; clc; close all;

%% Definicja filtru
FIRcoefs = [ 1 1 1 1 ];                 % Współczynniki filtru

filterOrder = length( FIRcoefs );       % Rząd filtru (liczba współczynników)

%% Definicja sygnału
samplesBeforeZero = 10;                 % Liczba próbek przed czasem t=0
samplesAfterZero = 10;                  % Liczba próbek po czasie t=0

signal = [ 1 ];                         % Jedna niezerowa próbka - impuls

%% Parametry analizy DFT

zeroPadding = 1000;                        % Dopełnienie zerami wag filtru

%% Generacja sygnału
% Generujemy samplesBeforeZero zerowych próbek (czasy t<0),
% dodajemy ciąg próbek dany przez signal i dopełniamy zerami tak, aby ilość
% próbek dla t>0 wyniosła samplesAfterZero (plus jedna próbka dla t=0)
samples = [ zeros( 1, samplesBeforeZero ) signal zeros( 1, samplesAfterZero - length( signal ) + 1) ];

% Wektor indeksów próbek (do wykresów)
samplesIdx = -samplesBeforeZero : samplesAfterZero;

% Wektor indeksów próbek po dekonwolucji - długość ciągu próbek + długość
% filtru - 1
convolutionIdx = -samplesBeforeZero : samplesAfterZero + filterOrder - 1;

%% Konwolucja sygnału i funkcji wag filtru
% Zamiast żmudnej pętli używamy funkcji Matlab'a
filteredSamples = conv( samples, FIRcoefs );

%% Wykresy w czasie
figure(1), subplot( 2, 1, 1 ); stem( samplesIdx, samples ), title( 'Próbki' );
grid on;
xlim( [ convolutionIdx( 1 )  convolutionIdx( end ) ] );
subplot( 2, 1, 2 ); stem( convolutionIdx, filteredSamples), title( 'Wynik filtracji' );
grid on;
xlim( [ convolutionIdx( 1 )  convolutionIdx( end ) ] );

%% Obliczenie funkcji przenoszenia filtru
% Dopełniamy wektor współczynników filtru zerami (po co?, dlaczego możemy 
% zrobić to asymetrycznie -- zera tylko z prawej strony?)
DTFTcoefs = [ FIRcoefs zeros( 1, zeroPadding ) ];

% Obliczamy DFT (albo DTFT jeśli zeroPadding jest odpowiednio duże (?) )
spectrum = fft( DTFTcoefs );
spectrumIdx = 0:length( spectrum ) - 1;

%% Wykres widma i fazy uzyskany z D(T)FT
figure(2), subplot(2,1,1), plot( spectrumIdx, 20*log10( abs( spectrum )) ), title( 'Logarytmiczne widmo amplitudowe D(T)FT' );
grid on;
xlim( [ 0 length( spectrum ) / 2 ] );
ylabel( 'Amplituda [dB]' );
% ylim( [ -40 20 ]);
grid on;

subplot(2,1,2), plot( spectrumIdx, ( 180 .* angle( spectrum ) ./ pi )), title( 'Widmo fazowe D(T)FT' );
grid on;
xlim( [ 0 length( spectrum )/2 ] );
ylim( [ -150 50 ]);
grid on;
 

%% Analiza funkcji przenoszenia filtru wbudowaną funkcją Matlab'a
figure(3), freqz( FIRcoefs );

%% Analiza położenia biegunów i zer wbudowaną funkcją Matlab'a
figure(4), zplane( FIRcoefs );


