#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto now = nums.begin();
        auto key = nums.begin();
        if(nums.size()<=1)
            return nums.size();
        while(now!=nums.end()-1){
            key =now+1;
            while(*key==*now&&key<nums.end()){
                key++;
                }
                nums.erase(now+1,key);
                if (now==nums.end()-1) {
                  break;
                }
            now++;
        }
        return nums.size();

    }
};

int main(void){
  Solution A;
  vector<int> input = {1,1};
  auto out = A.removeDuplicates(input);
  for(auto p:input)
    cout<<p<<" ";

  return 0;
}
