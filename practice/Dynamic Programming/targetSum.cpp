class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int t) {
        int sum = 0, n = nums.size();
        for(auto it: nums)
            sum += it;
        
        sum += t;
        if(sum & 1)
            return 0;
        sum /= 2;
        
        int dp[n+1][sum+1];
        memset(dp,0,sizeof(dp));
        
        for(int j = 0; j <= sum; j++)
            dp[0][j] = 0;
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        
        
        int cnt = 0;
        for(int i = 1; i <= n; i++){
              if(nums[i-1] == 0)
                    cnt++;
            for(int j = 1; j <= sum; j++){
              
                if(j-nums[i-1] >= 0 && nums[i-1] != 0)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum] * pow(2,cnt);
    }
};

//or

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int t) {
        int sum = 0, n = nums.size();
        for(auto it: nums)
            sum += it;
        
        sum += t;
        if(sum & 1)
            return 0;
        sum /= 2;
        
        int dp[sum+1];
        memset(dp,0,sizeof(dp));
        
        for(int i = 0; i <= n; i++)
            dp[0] = 1;
        
        
        int cnt = 0;
        for(int i = 1; i <= n; i++){
              if(nums[i-1] == 0)
                    cnt++;
            for(int j = sum; j >= 1; j--){
              
                if(j-nums[i-1] >= 0 && nums[i-1] != 0)
                    dp[j] = dp[j-nums[i-1]] + dp[j];
                
                else
                    dp[j] = dp[j];
            }
        }
        return dp[sum] * pow(2,cnt);
    }
};