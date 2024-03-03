system "mkdir -p plot"

set terminal gif animate delay 0 optimize size 960, 720

set output "plot/grid.gif"

#set view map
set cbrange [0:10]
set zrange [0:10]

set xrange [0:2000]
set yrange [0:2000]

datafile = "build/data/grid.dat"

stats datafile u 7

N=STATS_blocks

do for [i=0:N-2:1] {
    plot datafile index i u 1:2:4 w image notitle
    #splot datafile index i u 1:2:4 w pm3d notitle
}
```

