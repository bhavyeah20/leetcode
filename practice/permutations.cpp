class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(vector<int> &nums, int begin){
        if(begin == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        
        for(int i = begin; i < nums.size(); i++){
            swap(nums[i], nums[begin]);
            solve(nums, begin + 1);
            swap(nums[i], nums[begin]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        solve(nums, 0);
        return ans;
    }
};