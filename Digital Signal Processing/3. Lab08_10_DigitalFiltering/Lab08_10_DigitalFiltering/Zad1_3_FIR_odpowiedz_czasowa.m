clear; clc; close all;

%% Definicja filtru
filterOrder = 10;       % Rząd filtru (liczba współczynników)

%% Definicja sygnału
x = [];

for i = 0.1:0.02:0.2
    Fsig = i;             % Stosunek częstotliwości sygnału do częstotliwości Nyquista
    Amp = 1;                % Amplituda sygnału

    N = round( 12 / Fsig ); % Liczba próbek - 12 okresów sygnału

    %% Generacja sygnału

    sampledTime = 0:N-1;    % Wektor czasu = indeksy próbek

    % Generacja sygnału - sinus z wyzerowanym pierwszym okresem
    sampledSignal = Amp * sin( 2*pi * sampledTime * Fsig / 2 );
    sampledSignal( 1:ceil( 2/Fsig ) ) = 0;

    %% Generacja filtru FIR i filtracja
    % Filtr uśredniający - wszystkie współczynniki = 1/rząd filtru
    filterCoefs = ones( 1, filterOrder ) / filterOrder;

    % Dopełnienie współczynników zerami (na potrzeby wykresów)
    contFilterCoefs = [ filterCoefs zeros( 1, N - filterOrder ) ];

    % Filtracja sygnału
    % Zamiast konwolucji używamy funkcji filter z następującymi parametrami:
    %  * wektor współczynników licznika funkcji przenoszenia (filterCoefs w
    %    naszym przypadku)
    %  * wektor współczynników mianownika funkcji przenoszenia (1 - brak 
    %    wyrazów z^-k, czyli filtr typu FIR)
    %  * wektor próbek
    filteredSignal = filter( filterCoefs, 1, sampledSignal );

    % Wycinamy pierwsze N próbek przefiltrowanego sygnału (na potrzeby
    % wykresów)
    filteredSignal = filteredSignal( 1:N );

    %% Wykresy
    figure;
    plot( sampledTime, sampledSignal, 'bd-' );
    hold on;
    plot( sampledTime, filteredSignal, 'rd-' );
    legend( 'Sygnał oryginalny', 'Sygnał przefiltrowany' );
    grid on;
    hold off;
    xlabel('Indeks próbki');
    ylabel('Amplituda');
    title(['Sygnał przed i po filtracji (Fsig = ', num2str(Fsig), ')']);
end