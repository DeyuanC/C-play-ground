#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// a stupid idea using hash map
class Solution {
public:
    int romanToInt(string s) {
      unordered_map<string,int>::iterator it;
      unordered_map<string, int> hash = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}, {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};

      int length,sum,number;
      string str;
      sum=0;
      number=0;
      length = s.size();

      for (size_t i = 0; i < length; i++) {
        if (i==length-1) {
          str.clear();
          str.push_back(s[i]);
          if (hash.find(str) != hash.end()){
            it = hash.find(str);
            number = it->second;
            sum = sum+number;
            break;
          }
        }

        str.clear();
        str.push_back(s[i]);
        str.push_back(s[i+1]);
        if (hash.find(str) != hash.end()){
          it = hash.find(str);
          number = it->second;
          sum = sum+number;
          i++;
          continue;
        }
        str.pop_back();
        if (hash.find(str) != hash.end()){
          it = hash.find(str);
          number = it->second;
          sum = sum+number;
          continue;
        }
      }
      return sum;
    //  if (hash.find("CCC") != hash.end());
    }
};

int main(){

  string str("III");
  class Solution A;
  int answer = A.romanToInt(str);
  cout<<answer;
  return 0;
}
