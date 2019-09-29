#include<iostream>
#include<vector>
using namespace std;
//很慢
class Solution {
public:
    int maxArea(vector<int>& height) {
      int nums = height.size(); //nums>=2;
      int area_max = (height[0]<height[1])?height[0]:height[1];
      int temp;
      if (nums==2) {
        return area_max;
      }
      for(int i = 2; i<nums; i++){ //check height[i]
        for (int j = i-1; j >= 0; j--) {
          temp = (height[i]<height[j])?height[i]*(i-j):height[j]*(i-j);
          area_max = (temp>area_max)?temp:area_max;
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
