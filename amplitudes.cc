#include <iostream>
#include <fstream>

using namespace std;


#include "amplitudes.h"
#include "numerical.h"




int main()
{ 
  A00 myA00;

  double ds = 0.1;

  Quadr quad;
  Derivative<Quadr> Dq(quad, ds);

  for(int i=0; i<100; ++i){
    cout << i*ds << " " << quad(i*ds) << " " << Dq(i*ds) << endl;
  }












    /* //used to check if TwoDimFunc works
       Quadr myFquad;
       myFquad.set_y0(0.5);
       myFquad.set_x0(2);

       fstream out2("out2.dat",fstream::out);
       fstream outx("outx.dat",fstream::out);
       fstream outy("outy.dat",fstream::out);


       double xi, yj;
       double ds = 0.1;
       for(int i=0; i<100; ++i){
       for(int j=0; j<100; ++j){
       xi = ds * i;
       yj = ds * j;
       out2 << myFquad.get_f(xi,yj) << " "; 
       }
       out2 << endl;
       outx << i << " " << myFquad.get_f_x0(xi) << endl;
       outy << i << " " << myFquad.get_f_y0(xi) << endl;
       }

       cerr << "finished" << endl;
       */










    return 0;
  }
