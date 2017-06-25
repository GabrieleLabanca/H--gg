#include <iostream>
#include <fstream>

using namespace std;


#include "amplitudes.h"
#include "numerical.h"




int main()
{ 
  double ds = 0.1;
  double olds,news,diff;

  ParametersStruct myparam(0,0,0,1,1,2);
  
  // FIRST INTEGRAL
  A00 myAmp(myparam);
  Integral_TDF   I_myAmp_y(myAmp);

  Trapzd<Integral_TDF> myIntegral(I_myAmp_y,0,1);
  news = 0;
  do{
    olds = news;
    news = myIntegral.next();
    //cerr << news << endl;
  } while( abs(news-olds)>0.001 );
  cerr << "first integral: " <<  news << endl;


  // SECOND INTEGRAL
  /*A00_alt myAmp_alt(myparam);
  Integral_TDF    I_myAmp_alt_y(myAmp_alt);
  Derivative_TDF  D_myAmp_alt_y(I_myAmp_alt_y,ds);

  Trapzd<Derivative_TDF> myIntegral_alt(D_myAmp_alt_y,0,1);
  news = 0;
  do{
    olds = news;
    news = myIntegral_alt.next();
    //cerr << news << endl;
    diff = news - olds;
    //cerr << "diff " << diff << endl; 
  } while( abs(diff)>0.00001 );
  cerr << "second integral: " <<  news << endl;
  */
  onedim_A00_alt myAmp_alt(myparam);
  Trapzd<onedim_A00_alt> myIntegral_alt(myAmp_alt,0,1);
  news = 0;
  do{
    olds = news;
    news = myIntegral_alt.next();
    diff = news - olds;
  } while( abs(diff)>0.00001 );
  cerr << "second integral: " <<  news << endl;




/*
  cerr << "______________________________________\n TRIAL INTEGRALS\n";
  // TRIAL INTEGRAL
  linear mylin;
  Integral_TDF I_lin(mylin);
  Trapzd<Integral_TDF> myI_lin(I_lin,0,1);
  news = 0;
  do{
    olds = news;
    news = myI_lin.next();
    //cerr << news << endl;
    diff = news - olds;
    //cerr << "diff " << diff << endl; 
  } while( abs(diff)>0.00001 );
  cerr << "trial integral: " <<  news << endl;

  // TRIAL INTEGRAL_ALT
  linear_alt mylin_alt;
  Integral_TDF    I_lin_alt_y(mylin_alt);
  Derivative_TDF  D_lin_alt_y(I_lin_alt_y,ds);

  Trapzd<Derivative_TDF> myI_lin_alt(D_lin_alt_y,0,1);
  news = 0;
  do{
    olds = news;
    news = myI_lin_alt.next();
    //cerr << news << endl;
    diff = news - olds;
    //cerr << "diff " << diff << endl; 
  } while( abs(diff)>0.00001 );
  cerr << "trial integral_alt: " <<  news << endl;

  // TRIAL DERIVATIVE
  fstream out_trash("trash/strange_der.dat",fstream::out);
  strange_function mystrange;
  double dh = 0.001;
  Derivative_TDF dstrange(mystrange,dh);
  for(int i=0; i<1./dh; ++i){
    //out_trash << i*dh << " " << I_myAmp_alt_y(i*dh) << " " <<  D_myAmp_alt_y(i*dh) << " " << log(i*dh) << endl;
  }

  */










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
