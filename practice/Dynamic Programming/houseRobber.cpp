class Solution {
public:
    int dp[102][102];
    int money(int last, int i, vector<int> &nums){
        
        if(i == nums.size())
            return 0;
        
        if(dp[last][i] != -1)
            return dp[last][i];
        
        int cost1 = 0, cost2 = 0;
        if(last == 100 || i-last > 1){
            cost1 = nums[i] + money(i, i+1,nums);
        }
        
        cost2 = money(last,i+1,nums);
        
        return dp[last][i] =  max(cost1, cost2);
    }
    
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return money(100,0,nums);
    }
};