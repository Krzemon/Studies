%% Podstawy działania filtru FIR (o skończonej odpowiedzi impulsowej)
clear; clc; close all;

%% Definicja filtru
FIRcoefs = [ 1 1 1 1 ];                 % Współczynniki filtru

filterOrder = length( FIRcoefs );       % Rząd filtru (liczba współczynników)

%% Definicja sygnału
samplesBeforeZero = 10;                 % Liczba próbek przed czasem t=0
samplesAfterZero = 10;                  % Liczba próbek po czasie t=0

%signal = [ 1 ];                        % Jedna niezerowa próbka - impuls
signal = ones( 1, samplesAfterZero + 1 );
%% Parametry wyświetlania
FIRcoefsColors = [ 'm' 'b' 'g' 'r' ];   % Kolory kolejnych współczynników
                                        % UWAGA: przy zwiększeniu ilości
                                        % współczynników (rzędu) filtru
                                        % należy rozszerzyć ten wektor

%% Generacja sygnału
% Generujemy samplesBeforeZero zerowych próbek (czasy t<0),
% dodajemy ciąg próbek dany przez signal i dopełniamy zerami tak, aby ilość
% próbek dla t>0 wyniosła samplesAfterZero (plus jedna próbka dla t=0)
samples = [ zeros( 1, samplesBeforeZero ) signal zeros( 1, samplesAfterZero - length( signal ) + 1) ];

% Wektor indeksów próbek (do wykresów)
samplesIdx = -samplesBeforeZero : samplesAfterZero;

%% Animacja konwolucji - fitracji sygnału
% Wykład 9. -- Konwolucja widziana od strony wyjścia:
% "Aby wyliczyć sygnał wyjściowy należy odwrócić ciąg próbek odpowiedzi
% impulsowej !", czyli musimy odwrócić wektor współczynników filtru aby móc
% wykonać animację konwolucji:
FIRcoefsInv = flip( FIRcoefs );

% Inicjalizacja wektora przefiltrowanych próbek wartościami NaN (not a
% number) - wartości Nan nie są wyświetlane na wykresie
filteredSamples = NaN( 1, length( samplesIdx ));

% Wykonujemy pętlę po wszystkich próbkach, od czasu t = -samplesBeforeZero
% do t = samplesAfterZero - filterOrder (nie możemy policzyć konwolucji do
% chwili t = samplesAfterZero bo braknie nam próbek...)
for idX = -samplesBeforeZero + filterOrder - 1 : samplesAfterZero
    % Przełożenie granic sumowania na indeks wektora w Matlab-ie
    matlabIdx = idX + samplesBeforeZero + 1;
    
    % Obliczenie wartości aktualnie przetwarzaniej próbki
    filteredSamples( matlabIdx ) = sum( FIRcoefsInv .* samples( matlabIdx - filterOrder + 1: matlabIdx ) );

    % Wykres ciągu próbek
    figure(1), clf; subplot( 3, 1, 1 );
    stem( samplesIdx, samples, 'k' ), title( 'Ciąg próbek' );
    grid on;
    xlabel('Czas [s]');
    ylabel('Amplituda [V]');
    hold on;
    
    % Inicjacja wykresu współczynników filtru (same zera bez współczynników - te, różnymi
    % kolorami doda pętla)
    subplot( 3, 1, 2 );
    stem( samplesIdx, [ zeros( 1, matlabIdx - filterOrder )  NaN( 1, filterOrder ) zeros( 1, length( samplesIdx ) - matlabIdx ) ], 'k' )
    title( sprintf( 'Wagi filtru dla t = %d', idX ) );
    grid on;
    xlabel('Czas [s]');
    ylabel('Amplituda [V]');
    hold on;

    % Pętla rysująca kolejne współczynniki filtru
    for firIdx = 1 : filterOrder
        % Dodanie pokolorowanych próbek sygnału wejśiowego używanych w
        % danym kroku konwolucji
        subplot( 3, 1, 1 );
        stem( idX - filterOrder + firIdx, samples( matlabIdx - filterOrder + firIdx ), 'filled', FIRcoefsColors( firIdx ) );

        % Dodanie pokolorowanych współczynników filtru w aktualnej pozycji
        % czasowej
        subplot( 3, 1, 2 );
        stem( idX - filterOrder + firIdx, FIRcoefsInv( firIdx ), 'filled', FIRcoefsColors( firIdx ) );
    end

    % Wykres wyniku - filteredSamples
    subplot( 3, 1, 3 );
    stem( samplesIdx, filteredSamples, 'k' );
    title( 'Wynik konwolucji')
    xlim( [ -samplesBeforeZero samplesAfterZero ]);
    grid on;
    xlabel('Czas [s]');
    ylabel('Amplituda [V]');
    hold on;
    % Pokolorowanie wartości wyliczonej w aktualnym kroku
    stem( idX, filteredSamples( matlabIdx ), 'filled', FIRcoefsColors( filterOrder ) );
    
    % Przerwa przed następnym krokiem (można zakomentować w dalszej części
    % zadania)
    pause( 1 );
end