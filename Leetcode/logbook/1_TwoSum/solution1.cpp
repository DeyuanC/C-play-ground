//slow
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index_now =0;
        int index_new=0;
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            for(int j = i+1 ; j<nums.size();j++){
                index_now = i;
                index_new=j;
                if(nums[index_now]+nums[index_new]==target){
                    ans = {index_now,index_new};
                }


            }
        }
                                return ans;
    }
};
