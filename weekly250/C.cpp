class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        
        long long n = points.size(), m = points[0].size();
        long long currMax = 0;
        vector<vector<long long>> dp(n, vector<long long> (m));
        vector<long long> left(m);
        vector<long long> right(m);
        
        for(int j = 0; j < m; j++)
            dp[0][j] = points[0][j];
        
        for(long long i = 1; i < n; i++){
            left[0] = dp[i-1][0];

            for(long long j = 1; j < m; j++){
                left[j] = max(left[j-1], dp[i-1][j]+j);
            }

            right[m-1] = dp[i-1][m-1] -m +1;

            for(long long j = m-2; j >= 0; j--){
                right[j] = max(right[j+1],dp[i-1][j]-j);
            }
            
            for(long long j = 0; j < m; j++){
                dp[i][j] = points[i][j] + max(left[j]-j , right[j]+j);
            }
        }
            
        currMax = 0;
        for(long long j = 0; j < m; j++){
            currMax = max(currMax, dp[n-1][j]);
        }
        
        return currMax;
        
    }
};