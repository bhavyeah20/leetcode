class Solution {
public:
    unordered_map<int, int> cntM, cntN;
    int dp[601][101][101];
    int largestSubset(int i, int m, int n, int N){
        if(i == N)
            return 0;
        
        if(m == 0 && n == 0){
            return 0;
        }
        
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        
        if(m-cntM[i] >= 0 && n-cntN[i] >= 0){
            return dp[i][m][n] = max(1 + largestSubset(i+1, m-cntM[i], n-cntN[i], N), largestSubset(i+1,m,n,N));
        }
        
        return dp[i][m][n] = largestSubset(i+1,m,n, N);
        
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        cntM.clear(), cntN.clear();
        for(int i = 0; i < strs.size(); i++){
            for(auto ch: strs[i]){
                if(ch == '0')
                    cntM[i]++;
                
                else
                    cntN[i]++;
            }
        }
        
        return largestSubset(0,m,n,strs.size());
        
    }
};

//or

class Solution {
public:
    unordered_map<int, int> cntM, cntN;
   
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        int dp[N+1][m+1][n+1];
        cntM.clear(), cntN.clear();
        for(int i = 0; i < strs.size(); i++){
            for(auto ch: strs[i]){
                if(ch == '0')
                    cntM[i]++;
                
                else
                    cntN[i]++;
            }
        }
        
        for(int idx = 0; idx <= N; i++){
            dp[idx][0][0] = 0;
        }

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                dp[N][i][j] = 0;
            }
        }

        for(int idx = N-1; idx >= 0; idx--){
            for(int i = 0; i <= m; i++){
                for(int j = 0; j <= n; j++){
                    if(i-cntM[idx] >= 0 && j-cntN[idx] >= 0){
                        dp[idx][i][j] = max(1 + dp[idx+1][i-cntM[idx]][j-cntN[idx]], dp[idx+1][i][j]);
                    }

                    else
                        dp[idx][i][j] = dp[idx+1][i][j];
                }
            }
        }


        return dp[0][m][n];
        
    }
};
