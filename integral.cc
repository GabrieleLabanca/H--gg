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

int main()
{
  Sinus SIN;
  int N = 10;;
  for(int i=0; i<N; i++){
    double dt = M_PI/double(N);
    cerr << i*dt << " :: " << SIN(i*dt) << " " << sin(i*dt)  << endl;
  }

double a = 0;
double b = M_PI*0.3;
  Trapzd<Sinus> s(SIN,a,b);
  for(int i=0; i<10; i++){
    double Itrap = s.next();
    double Ireal = -(cos(b)-cos(a));
  cerr << i << " " <<  setprecision(5) << Itrap << " |  " << setprecision(5) << Ireal 
    << " ---> " << abs((Itrap-Ireal)/Ireal)
    << endl;
  }











  return 0;
}
