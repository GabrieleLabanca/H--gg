#include <iostream>
#include<iomanip>
#include <fstream>

using namespace std;


#include "amplitudes.h"
#include "numerical.h"
#include "physics.h"

const double mH = PhysConst::mH;
const double mt = PhysConst::mt;


int main()
{ 
  double ds = 0.01;
  double olds,news,diff;
  double counter;

  cerr 
    << setw(15) << left << "amplitudes" << "|"
    << setw(15) << left << "trapezoid"  << "|"
    << setw(15) << left << "montecarlo" << "|"
    << endl;



  amp00 my00;
  Integral_TDF myI00_y(my00);
  Trapzd<Integral_TDF> myI00(myI00_y,0,1);
  news = 0;
  counter = 0;
  do{
    olds = news;
    news = myI00.next();
    //cerr << news << endl;
  } while( abs(news-olds)>0.00001 && (++counter)<20 );
  cerr 
    << setw(15) << left << "Amplitude_00:" << "|"
    << setw(15) << left <<  news << "|";

  MontecarloTriangle<amp00> MC_a00(my00,100000);
  cerr 
    << setw(15) << left << MC_a00.integrate() << "|"
    << endl;


  amp12 my12;
  Integral_TDF myI12_y(my12);
  Trapzd<Integral_TDF> myI12(myI12_y,0,1);
  news = 0;
  counter = 0;
  do{
    olds = news;
    news = myI12.next();
    //cerr << news << endl;
  } while( abs(news-olds)>0.00001 && (++counter)<20 );
  cerr 
    << setw(15) << left << "Amplitude_12:" << "|"
    << setw(15) << left <<  news           << "|";

  MontecarloTriangle<amp12> MC_a12(my12,100000);
  cerr 
    << setw(15) << left << MC_a12.integrate() << "|"
    << endl;













  /*
     const double necessary = 0;
     ParametersStruct myparam(necessary,necessary,1.3,1,1,-0.8);

  // FIRST INTEGRAL
  A00 myAmp(myparam);
  Integral_TDF   I_myAmp_y(myAmp);

  Trapzd<Integral_TDF> myIntegral(I_myAmp_y,0,1);
  news = 0;
  counter = 0;
  do{
  olds = news;
  news = myIntegral.next();
  //cerr << news << endl;
  } while( abs(news-olds)>0.00001 && (++counter)<20 );
  cerr << "first integral: " <<  news << endl;

  // SECOND INTEGRAL
  onedim_A00_alt myAmp_alt(myparam);
  Trapzd<onedim_A00_alt> myIntegral_alt(myAmp_alt,0,1);
  news = 0;
  counter = 0;
  do{
  olds = news;
  news = myIntegral_alt.next();
  diff = news - olds;
  } while( abs(diff)>0.00001 && (++counter)<20 );
  cerr << "second integral: " <<  news << endl;
  */

  return 0;
}
