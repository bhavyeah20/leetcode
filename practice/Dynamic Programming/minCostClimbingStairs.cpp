class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,0);
        
        dp[n-1] = cost[n-1];
        dp[n-2] = cost[n-2];
        
        for(int i = n-3; i >=0; i--){
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        
        return min(dp[0], dp[1]);
    }
};

//or

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int plusTwo = cost[n-1];
        int plusOne = cost[n-2];
        
        for(int i = n-3; i >=0; i--){
            int val = cost[i] + min(plusOne, plusTwo);
            plusTwo = plusOne;
            plusOne = val;
        }
        
        return min(plusOne, plusTwo);
    }
};