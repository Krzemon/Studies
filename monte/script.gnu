set terminal png

set output "plot/p01.png"

set logscale x
set logscale y

set xrange [0:1]
set yrange [0:1]

datafile = "data/p01.dat"

stats datafile nooutput
N = STATS_records

do for [i=0:N-2:1] {
    plot datafile index i u 2:3:4 w image notitle
    #splot datafile index i u 1:2:4 w pm3d notitle
}
