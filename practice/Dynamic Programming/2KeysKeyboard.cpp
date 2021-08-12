class Solution {
public:
    int minSteps(int n) {
        
        if(n == 1)
            return 0;
    
        int dp[n+1];
        for(int i = 2; i <= n; i++){
            dp[i] = i;
            for(int j = 2; j * j <= i; j++){
                if(i % j == 0){
                    dp[i] = dp[i/j] + j;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};