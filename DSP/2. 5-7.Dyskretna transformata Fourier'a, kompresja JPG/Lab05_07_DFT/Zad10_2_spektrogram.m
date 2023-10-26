%% Przykład tworzenia spektrogramu z użyciem MDCT
clear; clc; close all; 
% MDCT (ang. modified discrete cosine transform) - Zmodyfikowana dyskretna
% transformacja cosinusowa.
% Generalna idea - liczymy transformatę (prawie) DCT, ale nie dla pełnego
% ciągu próbek, ale jego fragmentu. Co więcej, "zakładmy" na siebie
% sąsiednie fragmenty o połowę, czyli:
%  - Plik dźwiękowy ma N próbek pobranch z częstotliwością Fsmp
%  - Wybieramy długość ramki MDCT na K próbek.
%  - Obliczamy DCT dla próbek   0 -- K
%  - Obliczamy DCT dla próbek K/2 -- 3K/2
%  - Obliczamy DCT dla próbek   K -- 2K
%  - (...)
%  - Obliczamy DCT dla próbek N-K -- N
%  - Wyświetlamy wynik na wykresie 3D, gdzie:
%    - Numer ramki jest na osi X (proporcjonalne do czasu)
%    - Numer prążka DCT jest na osi Y (proporcjonalne do częstotliwości)
%    - Amplituda prążka DCT jest na osi Z

%% Długość ramki MDCT
frameSize = 1024;           % Długość ramki wyrażona w próbkach, powinna być 2^N

%% Wczytanie pliku dżwiękowego
  [ samples, Fsmp ] = audioread( "media/dialog.mp3" );
% [ samples, Fsmp ] = audioread( "media/piano_scale.mp3" );
% [ samples, Fsmp ] = audioread( "media/2L-092_01_44kHz_32b.mp3" );

% load( 'strong.mat' )
% Fsmp = fs;
% samples = her;
% samples = him;

% Jeśli dżwięk jest stereo, bierzemy jeden z kanałów
samples = samples( :, 1 );

%% Obliczenie MDCT
% kbdwin - okno Kaiser-Bessel (może być inne)

mdctCoefs = mdct( samples, kbdwin( frameSize ));

%% Wykres spektrogramu

% Pobranie rozmiaru macierzy mdctCoefs:
% W kolumnach ummieszczone są DCT kolejnych ramek, czyli liczba kolumn to
% liczba ramek uzyskanych dla danego pliku, a liczba wierszy to liczba
% prążków w pojedynczym DCT.
[ dctLength, noOfFrames ] = size( mdctCoefs );

%frameTimeLength = 1;                    % Czas trwania (długość) ramki w [s] - DO UZUPEŁNIENIA
frameTimeLength = frameSize / Fsmp;
sampledTime = 0:frameTimeLength:(noOfFrames - 1) * frameTimeLength;
%fBase = 1;                              % Częstotliwość bazowa - DO UZUPEŁNIENIA
fBase = Fsmp / frameSize;
sampledFrequency = 0:fBase:(dctLength - 1) * fBase;

% Spektrogram, oś Z wyrażona w dB dzięki funkcji pow2db
figure, surf( sampledTime, sampledFrequency, pow2db( mdctCoefs.^2 ), 'EdgeColor', 'none' );
view( [0 90] );
xlabel( 'Czas [s]' );
ylabel( 'Częstotliwość [Hz]' );
axis( [ 0 sampledTime( end ) 0 sampledFrequency( end ) ] );
cb = colorbar;
cb.Label.String = 'Moc [dB]';

%% Odtwarzanie dźwięku
% PlaySound( samples, Fsmp );
