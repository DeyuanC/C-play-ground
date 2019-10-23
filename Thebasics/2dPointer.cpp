#include<iostream>

int main(){
  double* x[5];
  double array0[3]= {1,2,3};
  double array1[4]= {1,2,3,4};
  double array2[1]= {1};
  double array3[2]= {1,2};
  x[0] = array0;
  int size=length(x[0]);
  std::cout<<size;
  return 0;
}
