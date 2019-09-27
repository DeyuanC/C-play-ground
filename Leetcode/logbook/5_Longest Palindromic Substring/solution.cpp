#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
      int right = s.size()*2-1; // center only exists form pos left to right
      int left = 1;
      int length = s.size();
      int index_l,index_r;
      int length_old = 0;
      int count = 0;
      string str;
      if (right<0) {
        return "";
      }
      for (size_t i = left; i <= right; i++) {
        index_l=(i-1)/2;
        index_r=i/2;
        count=(index_l==index_r)?1:0;
        if (index_l==index_r) {
          index_l--;
          index_r++;
        }
        while(index_l>=0&&index_r<=length-1){
          if (s[index_l]==s[index_r]) {
            count=count+2;
            index_l--;
            index_r++;
            continue;
          }
          break;
        }
        if (count>=length_old) {
          length_old = count;
          str.clear();
          str.append(s,index_l+1,count);
        }
      }
      return str;
    }
};

int main(void){
  string str("babad");
  Solution sol;
  auto res = sol.longestPalindrome(str);
  std::cout<<res;
  return 0;
}
