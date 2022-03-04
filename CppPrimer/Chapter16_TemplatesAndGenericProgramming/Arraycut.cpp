#include<iostream>
#include"mytemplate.h"
#include<vector>
#include <typeinfo>
using namespace std;


int main(){
  vector<int> ary0 ={0,0,1,2,3,2,1,0,0,-1,-1,3,4};

  auto output = ArrayCut(ary0);
  for(auto &p:output){
    for(auto &pp:p)
      cout<<pp<<" ";
      cout<<endl;
    }
  return 0;
}
//the declaration and definition of a template has to be in the same file and preferably in .h file.  a template function/class is not compiled, the template is compiled during the linking .
