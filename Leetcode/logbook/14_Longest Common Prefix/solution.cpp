#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      int flag=1;
      int counter =0;
      string output;
      char key;
      int size_min=10000;
      if (strs.empty()) {
        return "";
      }
      for(auto r:strs){
        size_min=(r.size()>size_min)?size_min:r.size();
      }
      if (size_min==0) {
        return "";
      }


        for (int i =0; i < size_min; i++) {
          key = strs[0][i];
          for (size_t j = 0; j < strs.size(); j++) {
            flag=(key==strs[j][i])?flag:0;
          }
          if (flag==1) {
            output.push_back(key);
          }
          else{
            break;
          }
        }
      return output;
    }
};

int main(void){
  vector<string> str;
  str={};
  Solution sol;
  auto res = sol.longestCommonPrefix(str);
  cout<<res;
  return 0;
}
