#define ll long long
class Solution {
public:
  
    ll ways(vector<int> &nums, int i,int prev,ll mod, vector<vector<ll>> &dp){
        
        if(dp[prev][i] != -1)
            return dp[prev][i];

        ll cnt = 0;
        if(i == -1)
            return prev == 0;


        if(nums[i] == prev || nums[i] == prev-1){
            cnt = ((cnt % mod) + (ways(nums,i-1,nums[i],mod,dp) % mod)) % mod;
        }


        cnt = ((cnt % mod) + (ways(nums,i-1,prev,mod,dp) % mod)) % mod;


        return dp[prev][i] = cnt;

    }

    int countSpecialSubsequences(vector<int>& nums) {
        ll mod = 1e9+7;
        vector<vector<ll>> dp(4,vector<ll> (nums.size(),-1));

        return ways(nums,nums.size()-1,3,mod,dp) % mod;
    }
};