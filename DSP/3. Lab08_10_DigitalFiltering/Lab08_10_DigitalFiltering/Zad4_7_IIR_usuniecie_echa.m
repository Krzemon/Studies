%% Usunięcie echa za pomocą filtru IIR

% UWAGA: proszę najpierw wykonać skrypt Zad2_echo_autokorelacja aby
% wygenerować dane!

%% Definicja filtru
a = filterCoefs            % Mianownik funkcji przenosznia
b = 2                      % Licznik funkcji przenoszenia
        %a = [a gain]; ?
%jesli w zad 2 linia 38 zakomentowana to b =1 jesli tu 2 to tam odkomentuj
%% Filtracja sygnału
echoRemoved = filter( b, a, echoSamples );

%% Wykresy przebiegów czasowych
figure, plot( sampledTime, ( samples - echoRemoved ) ), title( 'Róznica względem oryginału' );
figure, plot( sampledTime, samples ), title( 'Oryginalne próbki' );
figure, plot( sampledTime, echoRemoved ), title( 'Próbki po usunięciu echa' );

%% Odtworzenie sygnału z echem i po jego usunięciu
PlaySound( echoSamples, Fsmp );
PlaySound( echoRemoved, Fsmp );
