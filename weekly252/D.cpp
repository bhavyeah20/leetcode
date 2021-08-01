
class Solution {
public:
  
    int ways(vector<int> &nums, int i,int prev,int mod){
        
        
        int cnt = 0;
        if(i == -1)
            return prev == 0;


        if(nums[i] == prev || nums[i] == prev-1){
            cnt += ways(nums,i-1,nums[i],mod);
        }


        cnt += ways(nums,i-1,prev,mod);

        return cnt;

    }

    int countSpecialSubsequences(vector<int>& nums) {
        int mod = 1e9+7;
        vector<vector<int>

        return ways(nums,nums.size()-1,3,mod);
    }
};