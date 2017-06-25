#include <iostream>
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

  return 0;
}
