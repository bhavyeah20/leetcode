class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        
        int cnt = 0, res = 0;
        for(int i = 0; i < nums.size(); i++){
            
            for(int j = i; nums[j] != -1; cnt++){
                int swapped = nums[j];
                nums[j] = -1;
                j = swapped;
            }
            
            res = max(res, cnt);
            cnt = 0;
        }
        
        return res;
    }
};