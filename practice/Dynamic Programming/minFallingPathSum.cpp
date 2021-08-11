class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n,0));
        
        for(int i = 0; i < n; i++)
            dp[n-1][i] = matrix[n-1][i];
        
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(j == 0)
                    dp[i][j] = matrix[i][j] + min({dp[i+1][j], dp[i+1][j+1]});

                else if(j == n-1)
                    dp[i][j] = matrix[i][j] + min({dp[i+1][j-1], dp[i+1][j]});
    
                else
                    dp[i][j] = matrix[i][j] + min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]});

                    
                }
        }
        int ans = 1e6;
        for(int j = 0; j < n; j++){
            ans = min(ans, dp[0][j]);
        }
        
        return ans;
    }
};


//or

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(2, vector<int> (n,0));
        
        for(int i = 0; i < n; i++)
            dp[1][i] = matrix[n-1][i];
        
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(j == 0)
                    dp[0][j] = matrix[i][j] + min({dp[1][j], dp[1][j+1]});

                else if(j == n-1)
                    dp[0][j] = matrix[i][j] + min({dp[1][j-1], dp[1][j]});
    
                else
                    dp[0][j] = matrix[i][j] + min({dp[1][j-1], dp[1][j], dp[1][j+1]});

                    
            }
            dp[1] = dp[0];
        }
        int ans = 1e6;
        for(int j = 0; j < n; j++){
            ans = min(ans, dp[1][j]);
        }
        
        return ans;
    }
};

//or

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(j == 0)
                    matrix[i][j] = matrix[i][j] + min({matrix[i+1][j], matrix[i+1][j+1]});

                else if(j == n-1)
                    matrix[i][j] = matrix[i][j] + min({matrix[i+1][j-1], matrix[i+1][j]});
    
                else
                    matrix[i][j] = matrix[i][j] + min({matrix[i+1][j-1], matrix[i+1][j], matrix[i+1][j+1]});

                    
                }
        }
        int ans = 1e6;
        for(int j = 0; j < n; j++){
            ans = min(ans, matrix[0][j]);
        }
        
        return ans;
    }
};
