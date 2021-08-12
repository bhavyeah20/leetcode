class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int dp[n]; // dp[i][j-1], dp[i][j]
        int prev = 0; //dp[i-1][j-1]
        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int old = dp[j];
                if(i == 0 || j == 0 || matrix[i][j] == '0')
                    dp[j] = matrix[i][j]-'0';

                else{
                 
                    dp[j] = 1 + min({dp[j], dp[j-1], prev});
                }
                ans = max(ans, dp[j]);
                
                
                prev = old;

                
            }
        }

        return ans*ans;
        
    }
};

//or

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
       int m = matrix.size(), n = matrix[0].size();
       int dp[m][n];

        int ans = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(i == 0)
                    dp[i][j] = matrix[i][j]-'0';

                else if(j == 0)
                    dp[i][j] = matrix[i][j]-'0';

                else{
                    if(matrix[i][j] == '1'){
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                    }
                    else
                        dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
                
            }
        }
        
        return ans*ans;
        
    }
};