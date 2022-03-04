#include<iostream>
#include<vector>
using namespace std;
//抄来的  核心是减少搜索次数，例如最开始 最左1 最右边10   那么在最左1的情况下，右边再怎么往左移也不会更大了，因为短板在左边，所以直接左边+1
class Solution {
public:
    int maxArea(vector<int>& height) {
      int nums = height.size(); //nums>=2;
      int area_max = 0;
      int temp;
      int i =0;
      int j=nums-1;
      while(i<j){
        temp = (height[i]<height[j])?height[i]*(j-i):height[j]*(j-i);
        area_max = (temp>area_max)?temp:area_max;
        if (height[i]<height[j]){
                    i++;
        } else{
          j--;
        }
      }
      return area_max;
    }
};

int main(void){
  vector<int> input;
  input ={1,8,6,2,5,4,8,3,7};
  Solution sol;
  auto res = sol.maxArea(input);
  cout<<res;
  return 0;
}
