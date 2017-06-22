#ifndef NUMERICAL_H
#define NUMERICAL_H

#include<cstdlib>

class Quadrature {
  public:
    int n;
    virtual double next() = 0;
};

template<class T>
class Trapzd : Quadrature {
  public:
    double a,b,s;
    T &func;
    Trapzd(){};
    Trapzd(T &funcc, const double aa, const double bb) :
      func(funcc), a(aa), b(bb) {n=0;}
    double next(){
      double x,tnm,sum,del;
      int it,j;

      n++;
      if(n==1)
        return (s=0.5*(b-a)*(func(a) + func(b)));
      else {
        for(it=1,j=1;j<n-1;j++) it*=2; 
        tnm=it;
        del=(b-a)/tnm;
        x=a+0.5*del;
        for(sum=0.0,j=0;j<it;j++,x+=del) sum += func(x);
        s=0.5*(s+(b-a)*sum/tnm);
        return s;
      }
    }
};

template<class T>
class Derivative
{
  public:
    T &func;
    Derivative(){};
    Derivative(T &funcc, double hh): func(funcc), h(hh) {}

    //f'_0 = 1/2h (f- - f+) 
    double operator()(double x) const { return -(func(x-h) - func(x+h))/(2.*h); }

  private:
    double h;

};


/*template<class T>
  class MontecarloTwo {
  using namespace std;
  public:
  double precision;
  double ax, bx, ay, by;
  T & func;
  Montecarlo() {}
  Montecarlo(T &funcc, const double aax, const double bbx, 
  const double aay, const double bby, double p): 
  func(funcc), ax(aax), bx(bbx), ay(aay), by(bby), precision(p) {}
  double integrate(){
  int seed = time(NULL);
  srand48(seed);
  for(int i=0; i< 10; i++)
  cerr << drand48() << endl ;

  }
  };

*/


#endif
