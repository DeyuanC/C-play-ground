#include<iostream>
#include<string>
#include<vector>
class A{
public:
  int value;
  A(int n){value=n;}
  A(const A& other){std::cout<<"copy";}
  void Print(){std::cout<<value<<std::endl;}
};

int main(void){
  A a=10;
  A b=a;
  b.Print();

  return 0;
}
