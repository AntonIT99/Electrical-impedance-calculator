# Gridlines
set grid

# Set x axis to logarithmic scale
set logscale x 10
set logscale y 10

set size 1,1
set origin 0,0
#set multiplot 
set multiplot layout 2,1 columnsfirst scale 1.1,0.9

# Magnitude response
# =============================================
#set size 1, 0.5
#set origin 0, 0.5
set xlabel "Frequency (Hz)"
set ylabel "Impedance |Z|"
plot "Impedance.dat" using 1:2 with lines title 'Module'


#Phase response
# =============================================
# Axis labels
set ylabel "Phase (degrees)"
set xlabel "Frequency (Hz)"
set logscale x 10
unset logscale y
plot "Impedance.dat" using 1:3 with lines title 'Phase'

pause -1 "Hit return"
unset multiplot
exit
