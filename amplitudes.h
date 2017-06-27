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
    void set_y0(double new_y0){ y0 = new_y0; }
    virtual double operator()(double z) = 0;
    double y0 = 0;
};

class OneDimFunc : public Functional
{
  public:
    double operator()(double z){ return fction(z); }

  private:
    virtual double fction(double x) = 0;
};

class TwoDimFunc : public Functional
{
  public:
    double get_f(double x, double y){ return fction(x,y); }
    double get_f_y0(double x){ return fction(x,y0); }
    double get_f_x0(double y){ return fction(x0,y); }
    //void set_y0(double new_y0){ y0 = new_y0; }
    void set_x0(double new_x0){ x0 = new_x0; }
    void set_flag(char c){ fix_var_flag = c; }
    double operator()(double z) 
    { 
      if(fix_var_flag=='x') return fction(x0,z);
      else if(fix_var_flag=='y') return fction(z,y0);
    }
  private:
    char fix_var_flag = 'y'; //tells which variable is fixed
    double x0 = 0;
    //double y0 = 0;
    virtual double fction(double x, double y) = 0;
};


template <class T>
class Trapzd;

class Integral_TDF : public Functional
{
  public:
    Integral_TDF(Functional &funcc) : func(&funcc) {}
    double operator()(double y)
    {
      (*func).set_y0(y);
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





class ParametersStruct
{
  public:
    ParametersStruct(double a, double b, double c, double d, double e, double f): aa(a),bb(b),cc(c),dd(d),ee(e),ff(f) {}
    double aa,bb,cc,dd,ee,ff;
};

class amp00 : public TwoDimFunc, public PhysConst
{
  private:
    double fction(double x, double y){ return ( 2*mt*mt+mH*mH*0.5*(-1-4*x*y) ) / ( mt*mt - x*y*mH*mH*0.5 ); }
};

class amp12 : public TwoDimFunc, public PhysConst
{
  private:
    double fction(double x, double y){ return ( 1+4*x ) / ( mt*mt - x*y*mH*mH*0.5 ); }
};






/*
class A00 : public TwoDimFunc, public PhysConst
{
  public:
    A00(ParametersStruct param): a(param.aa), b(param.bb), c(param.cc), d(param.dd), e(param.ee), f(param.ff) {}
  private:
    double a, b, c, d, e, f;
    double fction(double x, double y){ return 1/(a*x*x+b*y*y+c*x*y+d*x+e*y+f); }
    //double fction(double x, double y){ return (1-2*x-2*y-4*x*y) / (mt*mt - x*y*mH*mH*0.5); }
};

class onedim_A00_alt : public PhysConst
{ 
  public:
    double operator()(double y){ return (fction(1-y,y) - fction(1-y,0)); }
    onedim_A00_alt(ParametersStruct param): a(param.aa), b(param.bb), c(param.cc), d(param.dd), e(param.ee), f(param.ff) {}
  private:
    double a, b, c, d, e, f;
    double fction(double x, double y){ return log((c*x*y+d*x+e*y+f)/(d*x+f)) / (c*x+e);  }
};
*/


/*

class linear : public TwoDimFunc, public PhysConst
{
  private: 
    double fction(double x, double y){ return 1; }
};

class linear_alt : public TwoDimFunc, public PhysConst
{
  private:
    double fction(double x, double y){ return y  ; }
};


class strange_function : public OneDimFunc
{
  private:
    double fction(double x){ return (x-1)*(x-1); } //+(x-1)*(x-1)-std::sin(4*x); }
    };


   class Ampl : public TwoDimFunc, public PhysConst
   {
   public:
   Ampl(double aa, double bb, double cc, double dd, double ee, double fctionf): 
   a(aa), b(bb), c(cc), d(dd), e(ee), f(ff) {}
   private:
   double a,b,c,d,e,f;
   double fction
   */
/*
   class Quadr : public TwoDimFunc
   {
   private:
   double fction(double x, double y){ return x*x + y*y; }
   };*/
#endif
