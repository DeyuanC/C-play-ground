#include<iostream>
using namespace std;


int main(){
  int i =42; //i is lvale
  int &lr = i; // ok  l ref binds to a lvale
  const &k_lr = i*2; // ok for a const l reference 
  //int &lr2 = i*2; //error  i*2 is a rvalue;
  int &&rr = i*2; //ok  i*2 is a rvalue;
  return 0;
}
