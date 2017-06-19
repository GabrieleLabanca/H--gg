#include<iostream>
#include<iomanip>
#include<cmath>
#include"numerical.h"

using namespace std;

// int operator()(int y) const { return x + y; }
class Sinus
{
  public:
    Sinus() {};
    double operator()(double t) const { return sin(t); }
};

class PhysConst
{
  protected:
    double mH = 125.09; //GeV
    double mt = 172.44; //GeV
};

class integrA : PhysConst
{
  public:
    integrA() {}
    //void setEnergy(double Energy1, double Energy2) { E1 = Energy1; E2 = Energy2; }
    double operator()(double x, double y) const { return (1-2*x-2*y-4*x*y)/(mt*mt - x*y*mH*mH/2.); }
};


int main()
{
  integrA myint;
  int N = 100;
  double dt = M_PI/double(N);
  for(int i=0; i<N; i++){
    cout << i << " ";
    for(int j=0; j<N; j++){
      if (j<i){
        double tres = myint(i*dt,j*dt);
        if(tres>-1 and tres<0.5) cout << " " << myint(i*dt,j*dt);
        else cout << 0;
      }
      else cout << " " << 0;
    }
    cout << endl;
  }

  Sinus SIN;
  double a = 0;
  double b = M_PI*0.3;
  Trapzd<Sinus> s(SIN,a,b);
  for(int i=0; i<25; i++){
    double Itrap = s.next();
    double Ireal = -(cos(b)-cos(a));
    cerr << i << " " <<  setprecision(10) << Itrap << " |  " << setprecision(10) << Ireal 
      << " ---> " << abs((Itrap-Ireal)/Ireal)
      << endl;
  }











  return 0;
}
