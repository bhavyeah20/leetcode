class Solution {
public:
    int minimumTotal(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid.size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        
        
        for(int j = n-1; j >= 0; j--){
            dp[m-1][j] = grid[m-1][j];
        }
        
        for(int i = m-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        
        
        return dp[0][0];
    }
};
