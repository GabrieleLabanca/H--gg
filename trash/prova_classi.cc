#include <iostream>

using namespace std;


class funtore
{
  public:
    virtual double operator()(double z) = 0;
};


class increaser : public funtore
{
  public:
    double operator()(double z){ return z+1; }
};

class summer : public funtore
{
  public:
    funtore *func;
    summer(funtore &funcc) : func(&funcc) {}
    double operator()(double z)
    {
      double sum = 0;
      for(int i=0; i<int(z); ++i){
        sum += (*func)(i);
      }
      return sum;
    }
};

class mean : public funtore
{
  public:
    funtore *func;
    mean(funtore &funcc) : func(&funcc) {}
    double operator()(double z)
    {
      return (*func)(z)/z;
    }
};





int main()
{
  increaser A;
  summer B(A);
  mean C(B);

  cerr << C(3) << endl;
















  return 0;
}
