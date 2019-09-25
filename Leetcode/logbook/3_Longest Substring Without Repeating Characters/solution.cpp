#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int length = s.length();
      int longest=1;
      int longest_reverse=1;
      int i,j;
      if (length<=1) {
        return length;
      }
      for (i = 1; i < length; i++) { // check s[i] only
        for (j = i-1; j >=i-longest_reverse; j--) {
          if (s[i]==s[j]) {
            break;
          }
        }
        longest_reverse = i-j;
        longest=(longest<=longest_reverse)?longest_reverse:longest;
      }
          return longest;
    }
};
int main(void) {
  string str("abcabcbb");
  Solution sol;
  auto res = sol.lengthOfLongestSubstring(str);
  cout<<res;
  return 0;
}
