#ifndef AMPLI_H
#define AMPLI_H

//#include <iostream>
//#include <iomanip>
#include <cmath>
//#include <fstream>

#include "physics.h"

class TwoDimFunc
{
  public:
    double get_f(double x, double y){ return f(x,y); }
    double get_f_y0(double x){ return f(x,y0); }
    double get_f_x0(double y){ return f(x0,y); }
    void set_y0(double new_y0){ y0 = new_y0; }
    void set_x0(double new_x0){ x0 = new_x0; }
    void set_flag(char c){ fix_var_flag = c; }
    double operator()(double z) //const
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



class A00 : public TwoDimFunc, public PhysConst
{
  private:
    double f(double x, double y){ return (1-2*x-2*y-4*x*y) / (mt*mt - x*y*mH*mH*0.5); }
};









   class Quadr : public TwoDimFunc
   {
   private:
   double f(double x, double y){ return x*x + y*y; }
   };
   






#endif
