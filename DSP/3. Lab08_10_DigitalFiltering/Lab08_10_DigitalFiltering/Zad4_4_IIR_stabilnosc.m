%% Stabilność filtrów IIR, wpływ przybliżeń
clear; clc; close all;

%% Równanie filtru
% Zadajemy współczynniki filtru "ręcznie", aby móc łatwo posterować
% precyzją (dokladnością) i zaokrągleniem
a = [ 1  3.6  4.86  2.916  0.6561 ];
%a = [ 1  3.6  4.86  2.92  0.66 ];  przyblizajac wspolczynniki filtr moze
%nie byc stabilny
b = [ 1 ];

%% Bieguny i zera
zplane( b, a );

%% Odpowiedź impulsowa
figure, impz( b, a );
