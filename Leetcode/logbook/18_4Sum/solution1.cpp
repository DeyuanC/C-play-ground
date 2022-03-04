// 2019/6/23 
// 使用 string 和 unordered set来判断重复 但是这并不好 字符串处理 以及to_string 都太慢了
//更好的方法来去重应该是在穷举的过程中就完成排序
#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    unordered_set<string> myset;
    unordered_set<string>::iterator got;
    string str1;
    vector<vector<int>> solution;
    vector<int> sub_solution(4);
    int n = nums.size();
    int i,j,k,l;
    //unordered_set<vector<int>>::iterator got;
    for(i =0;i<n-3;i++){
        j=i+1;
        for(j;j<n-2;j++){
            k=j+1;
            for(k;k<n-1;k++){
                l=k+1;
                for(l;l<n;l++){
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                      str1 = to_string(nums[i]) +"," +to_string(nums[j]) +","+to_string(nums[k]) +","+to_string(nums[l]) +",";
                       got = myset.find (str1);
                        if(got==myset.end()){
                          sub_solution={nums[i],nums[j],nums[k],nums[l]};
                          solution.push_back(sub_solution);

                          for (size_t i1 = 0; i1 < 4; i1++) {
                            for (size_t i2 = 0; i2 < 4; i2++) {
                              if (i2==i1)
                                continue;
                              for (size_t i3 = 0; i3 < 4; i3++) {
                                if (i3==i1||i3==i2)
                                  continue;
                                for (size_t i4 = 0; i4 < 4; i4++) {
                                  if (i4==i1||i4==i3||i4==i2)
                                    continue;
                                  str1 = to_string(sub_solution[i1]) +"," +to_string(sub_solution[i2]) +","+to_string(sub_solution[i3]) +","+to_string(sub_solution[i4]) +",";
                                  myset.emplace(str1);
                              }
                            }
                          }
                        }
                      }

                        else{
                          continue;
                        }
                    }
                }
            }
        }
    }
    cout<<"solutions are"<<endl;
    for (auto &p:solution){
      for(auto &pp:p)
        cout<<pp<<" ";
        cout<<endl;
    }
    return solution;
    }
};

int main(){
  vector<int> nums;
  nums = {0,0,0,0,0,0,0,0};
  Solution sol;
  auto res = sol.fourSum(nums,0);

  return 0;
}
