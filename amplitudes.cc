#include <iostream>
#include <fstream>

using namespace std;


#include "amplitudes.h"
#include "numerical.h"




int main()
{ 
  A00 myAmp;
  A00_alt myAmp_alt;

  double ds = 0.1;

  Integral_TDF    A00_y(A00);
  /////// TODO
  // for some reason, it is not recognised as an Integral_TDF
  // compiler: "no known conversion for argument 1 from 'Integral_TDF(A00)' to 'Integral_TDF&'"
  // the same for the "alt" integral

  Trapzd<Integral_TDF> myIntegral(A00_y,0,1);
  double olds,news;
  news = 0;
  do{
    olds = news;
    news = myIntegral.next();
  } while( (news-olds)>0.001 );
  cerr << "first integral: " <<  news << endl;

  Integral_TDF    A00_alt_y(A00_alt);
  Derivative_TDF  DA00_alt_y(A00_alt_y,ds);














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
