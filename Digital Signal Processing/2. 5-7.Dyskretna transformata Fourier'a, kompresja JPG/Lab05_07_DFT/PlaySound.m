function [] = PlaySound( data, Fsmp )
%% Parametry
%   data - ciąg próbek zawierających sygnał audio
%   Fsmp - częstotliwość próbkowania ciągu
%% Ciało funkcji
    audioplay = audioplayer( data, Fsmp );
    playblocking( audioplay );

end