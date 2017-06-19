#ifndef NUMERICAL_H
#define NUMERICAL_H

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
class TrapzdTwo : Quadrature { //two-variable function
  public:
    double ax,bx,ay,bys;
    T &func;
    TrapzdTwo(){};
    TrapzdTwo(T &funcc, const double aax, const double bbx, const double aay, const double bby) :
      func(funcc), ax(aax), bx(bbx), ay(aay), by(bby) {n=0;}
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

#endif
