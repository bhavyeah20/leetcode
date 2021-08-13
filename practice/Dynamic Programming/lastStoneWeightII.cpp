class Solution {
public:

    int dp[30][6001];
    
    int solve(int i, int sum, vector<int> &stones){
        if(i == stones.size()){
            return abs(sum);
        }
        
        if(dp[i][3000+sum] != -1)
            return dp[i][3000+sum];
        
        return dp[i][3000+sum] =  min(solve(i+1, sum + stones[i], stones), solve(i+1, sum - stones[i], stones));
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,stones);
    }
};