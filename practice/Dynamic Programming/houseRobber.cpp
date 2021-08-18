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

//or

class Solution {
public:

    
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n+2][2];
        memset(dp,0,sizeof(dp));
        
        
        for(int i = n-1; i >= 0; i--){
            dp[i][1] = max(dp[i+2][0], dp[i+2][1]) + nums[i];
            dp[i][0] = max(dp[i+1][0], dp[i+1][1]);
        }
        
        return max(dp[0][1], dp[0][0]);
        
    }
};


//or

class Solution {
public:

    
    int rob(vector<int>& nums) {
        int n = nums.size();
        int picked = 0, notPicked = 0;
        for(int i = n-1; i >= 0; i--){
            int tmp = max(nums[i] + picked, notPicked);
            
            picked = notPicked;
            notPicked = tmp;
        }
        
        return max(picked, notPicked);
        
    }
};