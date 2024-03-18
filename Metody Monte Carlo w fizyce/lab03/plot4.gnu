set terminal pngcairo
set output "./plot/NormRotate.png"

set xlabel "Polozenie X"
set ylabel "Polozenie Y"

set xrange [-4:4]
set yrange [-4:4]


plot "./data/NormRotate.dat" using 1:2 linecolor rgb "blue" pointtype 6