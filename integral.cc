#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>
#include"numerical.h"

using namespace std;

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
    double operator()(double x, double y) const { return 10e3*(1-2*x-2*y-4*x*y)/(mt*mt - x*y*mH*mH/2.); }

};

class integrB : PhysConst
{
  public:
    integrB(){}
    double operator()(double x, double y) const { return -2.*(1-2*x-2*y-4*x*y)/(x*mH*mH)*log(1-0.5*x*y*mH*mH/(mt*mt)); }
};

double prism(double A, double B)
{
  return 2;
}


int main()
{
  integrA myint;
  integrB regint;

  fstream file_raw("data_raw.dat",fstream::out);
  fstream file_reg("data_reg.dat",fstream::out);

  int N = 150;
  double dt = 1./double(N);
  cerr << "dt is " << dt << endl;
  for(int i=0; i<N; i++){
    file_raw << i*dt << " ";
    file_reg << i*dt << " ";

    for(int j=0; j<N; j++){
      if (j<i){
        //double tres = myint(i*dt,j*dt);
        file_raw << " " <<  myint(i*dt,j*dt);
        file_reg << " " << regint(i*dt,j*dt);
        //if(tres>-1 and tres<0.5) file_raw << " " << myint(i*dt,j*dt);
        //else file_raw << 0;
      }
      else{
        file_raw << " " << log(-1);
        file_reg << " " << log(-1);
      }
    }
    file_raw << endl;
    file_reg << endl;
  }


  int seed = time(NULL);
  srand48(seed);
  int Ntry = 100000;
  int hit = 0;
  int miss = 0;
  double MAX_H = 10; 
  double rndx, rndy, rndz;
  double funval;
  for(int i=0; i<Ntry; i++){
    rndx = drand48();   
    rndy = drand48()*rndx; 
    rndz = drand48()*MAX_H;
    funval = myint(rndx,rndy); ///insert here the function
    if(funval>rndz){
      hit++;
    }
    else miss++;
  }
  double volume = 0.5*MAX_H;
  cerr << "total volume " << volume << endl;
  cerr << "hit  "<< hit << " miss " << miss << endl;
  cerr << "INTEGRAL = " << volume*double(hit)/(double(hit)+double(miss)) << endl;







  return 0;
}
