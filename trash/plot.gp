set style fill solid 1.0 border rgb 'black'
unset key
set style fill solid 0.0 border

set terminal pngcairo

set output 'images/regularized.png'
set xrange [0:100]
set yrange [0:0.001]
plot for[ii=0:99] 'data_reg.dat' u 1:(column(ii)+ii/100000.) ls 1 w filledcu

set output 'images/raw_function.png'
set xrange restore
set yrange restore
plot for[ii=0:99] 'data_raw.dat' u 1:(column(ii)+ii/10.) ls 1 w filledcu
