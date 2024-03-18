# Zapisywanie wykresu do pliku
set terminal png

# Ustawienia wykresu
set title "Histogram dla rozkładu złożonego"
set xlabel "x"
set ylabel "Znormalizowana liczba zliczeń"
#set yrange [0.8:1.15]

# Szerokość binu
binwidth = 1.0 / 10
# Funkcja określająca numer binu
bin(x, width) = width * floor(x / width)
set boxwidth binwidth


set output './plot/zlozony.png'

# Rysowanie histogramu
plot './data/zlozony.dat' using (bin($1, binwidth)):(column(2)) smooth frequency with boxes title "Histogram", \
     './data/theory.dat' with lines title "Krzywa teoretyczna"
