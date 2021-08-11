class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        
        dp[m-1][n-1] = grid[m-1][n-1];
        
        for(int i = m-2; i >= 0; i--){
            dp[i][n-1] = grid[i][n-1] + dp[i+1][n-1];
        }
        
        for(int j = n-2; j >= 0; j--){
            dp[m-1][j] = grid[m-1][j] + dp[m-1][j+1];
        }
        
        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >= 0; j--){
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        
        return dp[0][0];
    }
};

//or
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(2, vector<int> (n,0));
        
        dp[1][n-1] = grid[m-1][n-1];
              
        for(int j = n-2; j >= 0; j--){
            dp[1][j] = grid[m-1][j] + dp[1][j+1];
        }
        
        for(int i = m-2; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                
                if(j == n-1){
                    dp[0][j] = grid[i][j] + dp[1][j];
                }
                
                else                
                    dp[0][j] = grid[i][j] + min(dp[0][j+1], dp[1][j]);
            }

            dp[1] = dp[0];
            
        }
        
        if(m == 1) return dp[1][0];
        return dp[0][0];
    }
};

//or

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n,0);
        
        dp[n-1] = grid[m-1][n-1];
              
        for(int j = n-2; j >= 0; j--){
            dp[j] = grid[m-1][j] + dp[j+1];
        }
        
        for(int i = m-2; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                
                if(j == n-1){
                    dp[j] += grid[i][j];
                }
                
                else                
                    dp[j] = grid[i][j] + min(dp[j+1], dp[j]);
            }

            
        }
        
        return dp[0];
    }
};