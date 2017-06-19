set style fill solid 1.0 border rgb 'black'
unset key 
plot for[ii=0:99] 'data.dat' u 1:(column(ii)+ii/100000.) title ''.ii ls 6
pause 10
#plot for[ii=0:99] 'data.dat' u 1:(column(ii)+ii/100000.) title ''.ii ls 6 w filledcu y1=0

