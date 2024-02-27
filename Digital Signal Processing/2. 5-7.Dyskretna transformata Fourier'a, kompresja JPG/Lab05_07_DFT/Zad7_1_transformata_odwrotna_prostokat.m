%% Transformata odwrotna - filtracja sygnału
clear; clc; close all;  dbclear all;
dbstop in dbStop;

%% Parametry rekonstrukcji
filterType = 2;     % 1 - filtr dolnoprzepustowy
                    % 2 - filtr górnoprzepustowy

%% Parametry sygnału
rectPeriod = 80;           % Okres sygnału prostokątnego wyrażony w próbkach (musi być parzysty!)
rectRept = 400;             % Ilość okresów w ciągu próbek
N = rectRept * rectPeriod;  % Długość ciągu próbek

%% Generacja sygnału
sampledTime = 0:(N-1);                                              % Wektor skwantowanego czasu = indeksy próbek
period = [ ones( 1, rectPeriod/2 ) zeros( 1, rectPeriod / 2 ) ];    % Jeden okres prostokąta
signal = repmat( period, 1, rectRept );                             % Sygnał prostokątny

%% Wykresy sygnału oryginalnego i jego widma
figure, subplot(3,2,1), plot( sampledTime, signal, 'bd-'), title( "Sygnał oryginalny" );
axis( [ 0 rectPeriod*3 -0.5 1.5 ] );
grid on;

spectrum = fft( signal );
Fbase = 1;
sampledFreq = 0:Fbase:(N-1)*Fbase;
subplot( 3, 2, 3), stem( sampledFreq, abs( spectrum ) );
ylim( [ 0 16000 ] );
grid on;

spectrum( abs(spectrum) < 1e-10 ) = complex( 0 );
subplot(3, 2, 5), stem( sampledFreq, angle( spectrum ) ./ pi);
grid on;

signalIdx = N / rectPeriod;
totalNumberOfHarmonics = floor( (N/2) / signalIdx ) - 1;

fprintf( "Całkowita liczba harmonicznych w widmie = %d\n", totalNumberOfHarmonics );

%% Odtwarzanie sygnału z ograniczonej ilości prążków widma
if filterType == 1
    filteredSpectrum = zeros( 1, N );   %  Inicializacja pustego widma
    for harmonicNumber = 1:2:totalNumberOfHarmonics
        % Przepisujemy z oryginalnego widma prążki obejmujące do harmonicNumber
        % harmonicznej sygnału 
        filteredSpectrum( 1, 1:harmonicNumber*signalIdx+1 ) = spectrum(  1, 1:harmonicNumber*signalIdx+1 );
        filteredSpectrum( 1, N-harmonicNumber*signalIdx:N ) = spectrum(  1, N-harmonicNumber*signalIdx:N );
        
        % Transformata odwrotna
        reconstructedSignal = real( ifft( filteredSpectrum ) );
        
        % Wykresy
        subplot( 3, 2, 2 ), plot( sampledTime, reconstructedSignal, 'bd-'), title( sprintf( "Sygnał zrekonstruowany dla n=%d harmonicznych", harmonicNumber ) );
        axis( [ (rectRept/2)*rectPeriod (rectRept/2 + 3)*rectPeriod -0.5 1.5 ] );
        xlabel("t [s]");
        ylabel("amplituda");
        grid on;
    
        subplot( 3, 2, 4 ), stem( sampledFreq, abs( filteredSpectrum ) );
        ylim( [ 0 16000 ] );
        grid on;
        subplot( 3, 2, 6 ), stem( sampledFreq, angle( filteredSpectrum ) ./ pi);
        grid on;
        
        if harmonicNumber < 9
            dbStop();
        else
            pause( 0.5 );
        end
    end

%% Odtwarzanie sygnału z ograniczonej ilości prążków widma zaczynając od górnych częstotliwości
else
    filteredSpectrum = zeros( 1, N );   %  Inicializacja pustego widma
    for harmonicNumber = 1:2:totalNumberOfHarmonics
        % Przepisujemy z oryginalnego widma prążki obejmujące do harmonicNumber
        % harmonicznej sygnału 
        filteredSpectrum( 1, N/2 - harmonicNumber*signalIdx:N/2 + harmonicNumber*signalIdx + 1  ) = spectrum(  1, N/2 - harmonicNumber*signalIdx:N/2 + harmonicNumber*signalIdx + 1 );
        
        % Transformata odwrotna
        reconstructedSignal = real( ifft( filteredSpectrum ) );
        
        % Wykresy
        subplot( 3, 2, 2 ), plot( sampledTime, reconstructedSignal+0.5, 'bd-'), title( sprintf( "Sygnał zrekonstruowany od n=%d harmonicznej", totalNumberOfHarmonics - harmonicNumber ) );
        xlabel("t [s]");
        ylabel("amplituda");
        axis( [ (rectRept/2)*rectPeriod (rectRept/2 + 3)*rectPeriod -0.5 1.5 ] );

        grid on;
    
        subplot( 3, 2, 4 ), stem( sampledFreq, abs( filteredSpectrum ) );
        ylim( [ 0 16000 ] );
        grid on;
        subplot( 3, 2, 6 ), stem( sampledFreq, angle( filteredSpectrum ) ./ pi);
        grid on;
        
        if harmonicNumber < 3 || harmonicNumber > ( totalNumberOfHarmonics - 7 )
            dbStop();
        else
            pause( 0.5 );
        end
    end
end

%% Pusta funkcja pełniąca rolę pułapki zatrzymującej symulację.
function [] = dbStop()
end