%% Podstawy dyskretnej tranfoty Fouriera DFT
clear; clc; close all;

%% Parametry próbkowania
Fsmp = 16000;       % Częstotliwość próbkowania [Hz]
N = 16;             % Ilość próbek

%% Parametry sygnału
Fsig = 2000;        % Częstotliwość sygnału [Hz]
Amp = 1;            % Amplituda [V]
Phase = 0.5;        % Faza sygnału [pi]
DC = 2;             % Składowa stała sygnału [V]

%% Generacja sygnału i wykres przebiegu czasowego
Tsmp = 1 / Fsmp;    % Okres próbkowania [s]

sampledTime = 0:Tsmp:(N-1)*Tsmp;                                            
sampledSignal = DC + Amp * sin( 2*pi * Fsig * sampledTime + Phase*pi );    

figure(1), subplot(3,1,1), plot(sampledTime, sampledSignal, 'bx--'), title( 'Sygnał w czasie' );
grid on;

%% Obliczenie widma - DFT
spectrum = fft( sampledSignal );    

%% Widmo amplitudowe
amplitude = abs( spectrum );        

Fbase = Fsmp/N;                          
amplitudeNorm = amplitude/(N/2);        
amplitudeNorm(1) = amplitude(1)/N;                 
sampledFreq = 0:Fbase:(N-1)*Fbase;  

subplot(3,1,2),  stem( sampledFreq, amplitudeNorm ), title( 'Widmo amplitudowe' );
grid on;
xlabel('Częstotliwość [Hz]');
ylabel('Amplituda');

%% Faza
% Usunięcie błędów precyzji obliczeniowej: ustawiamy dokładnie zero tam,
% gdzie amplituda widma jest mniejsza od 10^(-6)

spectrum( abs(spectrum) < 1e-6 ) = complex( 0 );

subplot(3, 1, 3), stem( sampledFreq, angle( spectrum ) ./ pi ), title( 'Faza' );
xlabel('Częstotliwość [Hz]');
ylabel( 'Faza [pi]' );
grid on;

% Faza
phase = angle(spectrum)./pi;  

% Interpretacja teoretyczna
% Prążki sinusa odpowiadają fazie 0 lub pi (inaczej mówiąc, faza 0 lub 180 stopni)
% Prążki kosinusa odpowiadają fazie -0.5 lub 0.5 (inaczej mówiąc, faza -90 lub 90 stopni)

% Prążki sinusa
sinusIndices = mod(0:N/2-1, N) + 1;  
sinusPhase = angle(phase(sinusIndices)) ./ pi;
sinusMatrix = [sinusIndices; sinusPhase];
disp("Faza prążków sinusa (w pi):");
disp(sinusMatrix);

% Prążki kosinusa
cosinusIndices = mod(N/2:N-1, N) + 1;  
cosinusPhase = angle(phase(cosinusIndices)) ./ pi;
cosinusMatrix = [cosinusIndices; cosinusPhase];
disp("Faza prążków kosinusa (w pi):");
disp(cosinusMatrix);