//2019/6/23 抄来的
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        //sort nums as ascending order
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i = 0; i < len - 3; i++){
            //if left 2 is same, left++
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            //if all smallest value > target, return empty
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target){
                break;
            }
            //if left is lager negative than right 3 sum, left++
            if(nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target){
                continue;
            }
            for(int j = i + 1; j < len - 2; j++){
                //find the same value, just sum new one
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                //if left 4 sum is larger than target, return ans
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target){
                    break;
                }
                //if nums[i] + nums[j] + right 2 sum < target, find 2 value in j and len - 1 index
                if(nums[i] + nums[j] + nums[len-2] + nums[len-1] < target){
                    continue;
                }
                int left = j + 1, right = len - 1, diff = target - nums[i] - nums[j];
                while(left < right){
                    if(left >j+1 && nums[left] == nums[left-1]){
                        left++;
                        continue;
                    }
                    //if diff is smaller, left++
                    if(nums[left] + nums[right] < diff){
                        left++;
                    //if diff is larger, right--
                    }else if(nums[left] + nums[right] > diff){
                        right--;
                    //if diff == 0, reuturn [i,j,left, right] index
                    }else{
                        ans.push_back({nums[i], nums[j], nums[left++], nums[right--]});
                    }
                }
            }
        }
        return ans;
    }
};
