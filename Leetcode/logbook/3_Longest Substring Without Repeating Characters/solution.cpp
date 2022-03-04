#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int length = s.length();
    int longest = 1;
    int longest_reverse = 1;
    int i, j;
    if (length <= 1) {
      return length;
    }
    for (i = 1; i < length; i++) {  // check s[i] only
      for (j = i - 1; j >= i - longest_reverse; j--) {
        if (s[i] == s[j]) {
          break;
        }
      }
      longest_reverse = i - j;
      longest = (longest <= longest_reverse) ? longest_reverse : longest;
    }
    return longest;
  }
};

class Solution2 {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    auto length = s.length();
    map.reserve(length);
    int longest = 1;
    int index_left = 0;
    int i, j;
    if (length <= 1) {
      return length;
    }
    map[s[0]] = 0;
    for (i = 1; i < length; i++) {  // check s[i] only
                                    // overwrite
      if (map.find(s[i]) == map.end()) {
      } else {
        index_left = std::max(index_left, map[s[i]] + 1);
      }
      map[s[i]] = i;
      longest = std::max(longest, i - index_left + 1);
      if (index_left + longest > length) {
        break;
      }
    }
    return longest;
  }
};

int main(void) {
  string str("abcabcbb");
  Solution2 sol;
  auto res = sol.lengthOfLongestSubstring(str);
  cout << res;
  return 0;
}
