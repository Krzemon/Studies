set term pngcairo color enhanced solid font "Helvetica, 14"

system "mkdir -p plot"

#######################

set xlabel 'E [meV]'
set ylabel 'WF_N [arb. unit]'

set output "plot/WF_N.png"

plot "build/data/WF_N.dat" w l notitle,\
0 linecolor rgb "red" notitle

#######################
reset

set xlabel 'Zero No.'
set ylabel 'E [meV]'
set key left top

set xrange [0:8]


set output "plot/zeros.png"


plot "build/data/zeros.dat" u 1:2 w p ps 1.2 pt 7 t "N=100",\
"build/data/zeros.dat" u 1:3 w p ps 1.2 pt 7 t "N=300",\
"build/data/zeros.dat" u 1:4 w p ps 1.2 pt 7 t "analytical",\

#######################

reset

set xlabel 'x [nm]'
set ylabel 'WF [arb. unit]'
set key left bottom

set output "plot/WF.png"

plot "build/data/WF_down.dat" w l t "-5%",\
"build/data/WF.dat" w l t "0%",\
"build/data/WF_up.dat" w l t "+5%",\
0 linecolor rgb "red" notitle

#######################

reset

set xlabel 'W [meV]'
set ylabel 'E [meV]'
set key left bottom

set output "plot/zeros_PB.png"

plot "build/data/zeros_PB.dat" u 1:2 w l t "State 1",\
"build/data/zeros_PB.dat" u 1:3 w l t "State 2",\
"build/data/zeros_PB.dat" u 1:4 w l t "State 3",\
"build/data/zeros_PB.dat" u 1:5 w l t "State 4",\
"build/data/zeros_PB.dat" u 1:6 w l t "State 5",\
"build/data/zeros_PB.dat" u 1:7 w l t "State 6",\
"build/data/zeros_PB.dat" u 1:8 w l t "State 7"

#######################

reset

set xlabel 'x [nm]'
set ylabel 'WF [arb. unit]'
set key left bottom

set output "plot/WF_PB.png"

plot "build/data/WF_PB_1.dat" w l t "state 1",\
"build/data/WF_PB_2.dat" w l t "state 2",\
"build/data/WF_PB_3.dat" w l t "state 3",\
"build/data/WF_PB_4.dat" w l t "state 4",\
0 linecolor rgb "red" notitle

#######################

reset

set xlabel 'x [nm]'
set ylabel 'WF [arb. unit]'

set output "plot/WF_PB_W_S1.png"

plot "build/data/WF_PB_W_0_S_1.dat" w l t "W=0",\
"build/data/WF_PB_W_1_S_1.dat" w l t "W=100",\
"build/data/WF_PB_W_2_S_1.dat" w l t "W=200",\
"build/data/WF_PB_W_3_S_1.dat" w l t "W=300",\
"build/data/WF_PB_W_4_S_1.dat" w l t "W=400",\
"build/data/WF_PB_W_5_S_1.dat" w l t "W=500",\
"build/data/WF_PB_W_6_S_1.dat" w l t "W=600",\
"build/data/WF_PB_W_7_S_1.dat" w l t "W=700",\
"build/data/WF_PB_W_8_S_1.dat" w l t "W=800",\
"build/data/WF_PB_W_9_S_1.dat" w l t "W=900",\
"build/data/WF_PB_W_10_S_1.dat" w l t "W=1000"

set output "plot/WF_PB_W_S2.png"

plot "build/data/WF_PB_W_0_S_2.dat" w l t "W=0",\
"build/data/WF_PB_W_1_S_2.dat" w l t "W=100",\
"build/data/WF_PB_W_2_S_2.dat" w l t "W=200",\
"build/data/WF_PB_W_3_S_2.dat" w l t "W=300",\
"build/data/WF_PB_W_4_S_2.dat" w l t "W=400",\
"build/data/WF_PB_W_5_S_2.dat" w l t "W=500",\
"build/data/WF_PB_W_6_S_2.dat" w l t "W=600",\
"build/data/WF_PB_W_7_S_2.dat" w l t "W=700",\
"build/data/WF_PB_W_8_S_2.dat" w l t "W=800",\
"build/data/WF_PB_W_9_S_2.dat" w l t "W=900",\
"build/data/WF_PB_W_10_S_2.dat" w l t "W=1000"