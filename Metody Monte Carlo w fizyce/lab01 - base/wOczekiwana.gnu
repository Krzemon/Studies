set terminal pngcairo
set output "plot/wykres_kolumna_1_2.png"

set logscale xy
set xlabel "Wykładniki potęgi 10"
set ylabel "Druga kolumna"

# Ustawienie znaczników na osi X i Y w postaci wykładniczej
set format x "10^{%L}"
set format y "10^{%L}"

# Ustawienie znaczników na osi X na podstawie pierwszej kolumny
plot "./data/p01.dat" using (10**$1):(10**$2) with linespoints linecolor rgb "blue" pointtype 7 pointsize 1.5 title "Dane"
