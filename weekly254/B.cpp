class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i <= (nums.size()-1)/2; i++){
            ans.push_back(nums[i]);
            if(nums.size()-1-i != i)
                ans.push_back(nums[nums.size()-1-i]);
        }
        
        return ans;
    }
};