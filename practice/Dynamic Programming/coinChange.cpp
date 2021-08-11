
class Solution {
public:
    
    int coinChange(vector<int>& coins, int t) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (t+1,0));
        
        for(int i = 1; i <= t; i++){
            dp[0][i] = INT_MAX-1;
        }
        
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= t; j++){
                if(coins[i-1] <= j)
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                
                else
                    dp[i][j] = dp[i-1][j];
            }
            
        }
        
        return dp[n][t] == INT_MAX-1 ? -1 : dp[n][t];
    }
};

//or


class Solution {
public:
    
    int coinChange(vector<int>& coins, int t) {
        int n = coins.size();
        vector<vector<int>> dp(2, vector<int> (t+1,0));
        
        for(int i = 1; i <= t; i++){
            dp[0][i] = INT_MAX-1;
        }
        
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= t; j++){
                if(coins[i-1] <= j)
                    dp[1][j] = min(dp[0][j], 1 + dp[1][j-coins[i-1]]);
                
                else
                    dp[1][j] = dp[0][j];
            }
            
            dp[0] = dp[1];
            
        }
        
        return dp[1][t] == INT_MAX-1 ? -1 : dp[1][t];
    }
};

//or



class Solution {
public:
    
    int coinChange(vector<int>& coins, int t) {
        int n = coins.size();
        vector<int> dp(t+1,0);
        
        for(int i = 1; i <= t; i++){
            dp[i] = INT_MAX-1;
        }
        
        
        for(int i = 0; i < n; i++){
            for(int j = coins[i]; j <= t; j++){
                dp[j] = min(dp[j], 1 + dp[j-coins[i]]);
            }
            
        }
        
        return dp[t] == INT_MAX-1 ? -1 : dp[t];
    }
};