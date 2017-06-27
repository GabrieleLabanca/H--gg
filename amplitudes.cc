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

  return 0;
}
