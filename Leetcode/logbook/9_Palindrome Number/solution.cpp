#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        long inverse=0;
        long key = x;
        if(x<0)
            return false;

        while(x!=0){
            inverse = inverse*10 + x%10;
            x=x/10;
        }
        cout<<inverse-key;
        if(inverse-key==0){
            return true;
        }
        else{
            return false;
        }

    }
};

int main(void){
  Solution sol;
  sol.isPalindrome(121);
  return 0;
}
