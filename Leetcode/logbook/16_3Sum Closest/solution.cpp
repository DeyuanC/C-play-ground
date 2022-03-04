#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target){
    int n = nums.size();
    int dist_min = 10000;
    int dist =10000;
    int dist_old=10000;
    int res=0;
    int res_min=0;
    int i,j,k;
    i=0;
    j=1;
    k=2;
    if(n<3)
        return 0;
    if(n==3)
      return nums[0]+nums[1]+nums[2];

    sort(nums.begin(),nums.end());


    for(i;i<n-2;i++){
      for(j=i+1;j<n-1;j++){
        for(k=j+1;k<n;k++){
          res=nums[i]+nums[j]+nums[k]-target;
          dist = (res>=0)?res:-res;
          if(dist>dist_old){
            continue;
          }
          dist_old=dist;
          if(dist<dist_min){
            dist_min=dist;
            res_min=res+target;
          }
          if(dist_min==0)
            return res_min;
          while(k+1<n&&nums[k+1]==nums[k]){ //duplicate of k
            k++;
          }
        }
        while(j+1<n-1&&nums[j+1]==nums[j]&&j+1<k){ //duplicate of k
          j++;
                    }
      }
      while(i+1<n-2&&nums[i+1]==nums[i]&&i+1<j){ //duplicate of k
        i++;}
    }
      return res_min;
  }
};

class solution {
public:
int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3) return 0;
    int closest = nums[0]+nums[1]+nums[2];
    sort(nums.begin(), nums.end());
    for(int first = 0 ; first < nums.size()-2 ; ++first) {
        if(first > 0 && nums[first] == nums[first-1]) continue;
        int second = first+1;
        int third = nums.size()-1;
        while(second < third) {
            int curSum = nums[first]+nums[second]+nums[third];
            if(curSum == target) return curSum;
            if(abs(target-curSum)<abs(target-closest)) {
                closest = curSum;
            }
            if(curSum > target) {
                --third;
            } else {
                ++second;
            }
        }
    }
    return closest;
}
};
int main(void){
  Solution A;
  vector<int> input ={-1,0,1,2,-1,-4};
  cout<<"-1 is "<<input[-1];
  auto res = A.threeSumClosest(input,0);
  cout<<res;
  return 0;
}
