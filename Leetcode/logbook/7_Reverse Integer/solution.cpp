#include<iostream>
using namespace std;
#include <math.h>
#include<bits/stdc++.h>
class Solution {
public:
    int reverse(int x) {
      long output=0;
        while(x!=0){
          output = output*10 + x%10;
          x=x/10;
          if (output>INT_MAX||output<INT_MIN) {
            return 0;
          }
        }
        return output;
    }
};


int main(void){
  Solution sol;

  auto res = sol.reverse(2312);
  int x=0X80000000;
  cout<<0X7FFFFFFF<<endl<<INT_MAX<<endl;
  cout<<x<<endl<<INT_MIN;
  return 0;
}
