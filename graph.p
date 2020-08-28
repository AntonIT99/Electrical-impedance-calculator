set logscale x
set logscale x2
set log y
set grid x y2
set key default
unset log y2
set title "Module et phase du circuit"
set xlabel "w (rad/s)"
set ylabel "Module (Ohm)"
set y2label "Phase (rad)"
set ytics nomirror
set y2tics
set tics out
set xtics nomirror
set autoscale y
set autoscale y2
plot 'Impedance.dat' using 1:2 with lines  title "Module",\
 'Impedance.dat' using 1:3 with lines title "Phase" axes x1y2
pause -1
