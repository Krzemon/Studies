%% Projektowanie filtrów FIR
clear; clc; close all;

%% Definicja filtru
N = 31;                  % Rząd filtru (liczba współczynników)
K = 7;                  % Ilość jedynek (szerokość impulsu prostokątnego)

% Tworzymy filtr - impuls szerokości K symetrycznie otoczony zerami
zerosBefore = floor( ( N-K ) / 2 );
zerosAfter = ceil( ( N-K ) / 2 );

requestedH = [ zeros( 1, zerosBefore ) ones( 1, K ) zeros( 1, zerosAfter ) ];
flipud(requestedH);
%% Wykres zadanej funkcji przenoszenia
% Indeksy funkcji przenoszenia - 0d -fs/2 do fs/2
indexesSym = [ -ceil( N/2 )+1 : floor( N/2 ) ];

   %figure( 1 ), subplot(5,1,1); 
figure, stem(indexesSym, requestedH);
stem( indexesSym, requestedH );
title( 'Zadana funkcja przenoszenia' );
xlim( [ -ceil( N/2 )+1  floor( N/2 ) ] );

% Przesuwamy funkcję przenoszenia w zakres ( 0 - fs )
% Wykład W9, strona 3, górny wykres (c)
   %shiftedH = ifftshift( requestedH );

   %indexes = [ 0: N-1 ];
   %subplot(5,1,2); 
   %stem( indexes, shiftedH );
   %title( 'Przesunięta funkcja przenoszenia' );
   %xlim( [ 0 N-1 ] );

%% Obliczenie współczynników filtru

% Obliczamy transformatę odwrotną DFT
   %timeResponse = ifft( shiftedH );

   %subplot(5,1,3); 
   %stem( indexesSym, timeResponse );
   %title( 'Współczynniki filtru' );
   %xlim( [ -ceil( N/2 )+1  floor( N/2 ) ] );

% Przesuwamy współczynniki (fftshift) tak, by
% otrzymać indeksy od 0 do N
   %FIRcoefs = fftshift( timeResponse );
   %window = blackman(N)';
%inversal czy cos
%FIRcoefs = FIRcoefs .* window;
%FIRcoefs = FIRcoefs.*(-1);
   %FIRcoefs(16) = 1 + FIRcoefs(16);
   %subplot(5,1,4); 
   %stem( indexes, FIRcoefs );
   %FIRcoefs(1:2:N) = FIRcoefs(1:2:N).*(-1)
   %title( 'Przesunięte współczynniki filtru' );
   %xlim( [ 0 N-1 ] );
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Obliczenie współczynników filtru

% Obliczanie transformaty odwrotnej DFT
timeResponse = ifftshift(ifft(requestedH));

indexes = 0 : N-1;

figure, stem(indexes, timeResponse);
title('Współczynniki filtru');
xlim([0, N-1]);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Obliczenie i wykres rzeczywistej funkcji przenoszenia
% Obliczamy transformatę DFT wraz z zero padding = 1000
%realH = fft( FIRcoefs, 1000 );
realH = fftshift(fft(timeResponse, 1000));
spectrumIdx = 0:length( realH ) - 1;

   %subplot(5,1,5), plot( spectrumIdx, abs( realH ) ), title( 'Rzeczywista funkcja przenoszenia' );
figure, plot(spectrumIdx, abs(realH));
title('Rzeczywista funkcja przenoszenia');