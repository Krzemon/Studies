set terminal pngcairo
set output "./plot/Circle_Norm.png"

set xlabel "Polozenie X"
set ylabel "Polozenie Y"

set xrange [-1:1]
set yrange [-1:1]


plot "./data/Circle_Norm.dat" using 1:2 linecolor rgb "blue" pointtype 6