%% Widmo instrumentów muzycznych
clear; clc; close all; dbclear all;
dbstop in dbStop

%% Parametry skryptu
doPlaySound = 1;           % Włącz lub wyłącz odtwarzanie instrumentów

%% Instrumenty smyczkowe
fprintf( "Instrumenty smyczkowe\n" );

% plotInstrument( 'media/altowka_A4.mp3', doPlaySound );
plotInstrument( 'media/skrzypce_A4.mp3', doPlaySound );
% plotInstrument( 'media/wiolonczela_A4.mp3',doPlaySound );

dbStop();

%% Instrumenty strunowe
fprintf( "Instrumenty strunowe\n" );

plotInstrument( 'media/banjo_A4.mp3',doPlaySound );
plotInstrument( 'media/gitara_A4.mp3',doPlaySound );
% plotInstrument( 'media/mandolina_A4.mp3',doPlaySound );
plotInstrument( 'media/pianino_A4.mp3',doPlaySound );

dbStop();

%% Instrumenty dęte
fprintf( "Instrumenty dęte\n" );

plotInstrument( 'media/fagot_A4.mp3',doPlaySound );
plotInstrument( 'media/flet_A4.mp3',doPlaySound );
% plotInstrument( 'media/klarnet_A4.mp3',doPlaySound );
% plotInstrument( 'media/oboj_A4.mp3',doPlaySound );
% plotInstrument( 'media/puzon_A4.mp3',doPlaySound );
plotInstrument( 'media/trabka_A4.mp3',doPlaySound );

dbStop();

%% Inne - perkusyjne
fprintf( "Instrumenty inne (perkusyjne)\n" );

plotInstrument( 'media/dzwonek.mp3',doPlaySound );
% plotInstrument( 'media/perkusja_bas.mp3',doPlaySound );
plotInstrument( 'media/perkusja_talerz.mp3',doPlaySound );
% plotInstrument( 'media/perkusja_werbel.mp3',doPlaySound );

%% Zadania
% Wykonaj skrypt i przedystkutuj wyniki.
%
% Tego zadania nie trzeba umieszczać w raporcie.



%% Funkcja rysująca przebiegi i widmo instrumentu
function plotInstrument( fileName, playSound )
    [ samples, Fsmp ] = audioread( fileName );
    
    if playSound == 1
        PlaySound( samples, Fsmp );
    end
    
    N = length( samples );
    fBase = Fsmp / N;
    
    sampledFreq = 0:fBase:Fsmp-fBase;
    
    f = fft( samples );
    
    figure, subplot(3,1,1), plot( samples ), title( fileName, 'Interpreter','none' );
    subplot(3,1,2), plot( sampledFreq, abs(f) );
    xlim( [0 Fsmp/2]);

    subplot(3,1,3), plot( sampledFreq, abs(f) );
    xlim( [400 480]);
end

%% Pusta funkcja pełniąca rolę pułapki zatrzymującej symulację.
function [] = dbStop()
end