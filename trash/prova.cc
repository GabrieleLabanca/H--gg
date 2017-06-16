#include <iostream>

using namespace std;

int main()
{
  int it,j,pt;
  int n = 10;
  for(it=1,j=1,pt=1;j<n-1;j++){
    it <<= 1;
    pt*=2;
    cerr << it << " "<< pt << endl;
  }









  return 0;
}
