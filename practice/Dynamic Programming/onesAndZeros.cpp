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
   
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        int dp[m+1][n+1];
       
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = 0;
            }
        }

        for(int idx = 1; idx <= N; idx++){
            int one = 0, zero = 0;
                for(auto ch: strs[idx-1]){
                    if(ch == '0')
                        zero++;
                
                    else
                        one++;
                }
            
            
                for(int i = m; i >= 0; i--){
                    for(int j = n; j >= 0; j--){
                        if(i-zero >= 0 && j-one >= 0){
                            dp[i][j] = max(1 + dp[i-zero][j-one], dp[i][j]);
                        }

                        else
                            dp[i][j] = dp[i][j];
                    }
                }
        
        }

        return dp[m][n];
        
    }
};
