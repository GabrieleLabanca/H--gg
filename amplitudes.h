#ifndef AMPLI_H
#define AMPLI_H

//#include <iostream>
//#include <iomanip>
#include <cmath>
//#include <fstream>

#include "physics.h"
#include "numerical.h"

class Functional
{
  public:
    virtual double operator()(double z) = 0;
};

class TwoDimFunc : public Functional
{
  public:
    double get_f(double x, double y){ return f(x,y); }
    double get_f_y0(double x){ return f(x,y0); }
    double get_f_x0(double y){ return f(x0,y); }
    void set_y0(double new_y0){ y0 = new_y0; }
    void set_x0(double new_x0){ x0 = new_x0; }
    void set_flag(char c){ fix_var_flag = c; }
    double operator()(double z) 
    { 
      if(fix_var_flag=='x') return f(x0,z);
      else if(fix_var_flag=='y') return f(z,y0);
    }
  private:
    char fix_var_flag = 'y'; //tells which variable is fixed
    double x0 = 0;
    double y0 = 0;
    virtual double f(double x, double y) = 0;
};

/* // non risolve il problema
   class TDF_proxy
   {
   public:
   TDF_proxy(TwoDimFunction &funcc): func(funcc){}
   double operator()(double y)
   { 
   func.set_y0(y); 
   return func

   private:
   TwoDimFunc func;
   };
   */

template <class T>
class Trapzd;

class Integral_TDF : public Functional
{
  public:
    Integral_TDF(Functional &funcc) : func(&funcc) {}
    double operator()(double y)
    {
      Trapzd<Functional> int_method(*func,0,1-y);
      double olds,news;
      news = 0;
      do{
        olds = news;
        news = int_method.next();
      } while( (news-olds)>0.001 );
      return news;
    }
  private:
    Functional *func;
    double a,b;
};

template <class T>
class Derivative;

class Derivative_TDF : public Functional
{
  public: 
    Derivative_TDF(Functional &funcc, double hh) : func(&funcc), h(hh) {}
    double operator()(double z)
    {
      Derivative<Functional> der_method(*func,h);
      return der_method(z);
    }
  private:
    Functional *func;
    double h;
};

class A00 : public TwoDimFunc, public PhysConst
{
  private:
    double f(double x, double y){ return (1-2*x-2*y-4*x*y) / (mt*mt - x*y*mH*mH*0.5); }
};

class A00_alt : public TwoDimFunc, public PhysConst
{
  private:
    double f(double x, double y){ return -2.*(1-2*x-2*y-4*x*y)/(x*mH*mH)*log(1-0.5*x*y*mH*mH/(mt*mt));  }
};



/*
   class Ampl : public TwoDimFunc, public PhysConst
   {
   public:
   Ampl(double aa, double bb, double cc, double dd, double ee, double ff): 
   a(aa), b(bb), c(cc), d(dd), e(ee), f(ff) {}
   private:
   double a,b,c,d,e,f;
   double f
   */
/*
   class Quadr : public TwoDimFunc
   {
   private:
   double f(double x, double y){ return x*x + y*y; }
   };*/
#endif
