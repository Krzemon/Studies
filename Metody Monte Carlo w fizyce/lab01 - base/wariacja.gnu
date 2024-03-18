set terminal pngcairo
set output "plot/wykres_kolumna_1_3.png"

set logscale xy
set logscale xtics auto
set xlabel "Wykładniki potęgi 10"
set ylabel "Trzecia kolumna"
set title "Wykres kolumny 1 od kolumny 3"

plot "./data/your_data.dat" using 1:3 with lines title "Dane"
