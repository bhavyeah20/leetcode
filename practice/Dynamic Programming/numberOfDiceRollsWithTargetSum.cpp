#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;
    ll dp[31][1001];
    ll ways(ll i, ll t, ll f){
        if(i == t)
            return 1;
        if(t < i || i == 0 || t == 0)
            return 0;
        
        if(dp[i][t] != -1)
            return dp[i][t] % mod;
        
        int ans = 0;
        for(int k = 1; k <= f; k++){
            if(t-k >= 0)
                ans = (ans % mod + ways(i-1,t-k,f) % mod) % mod;
        }
        
        return dp[i][t] = ans % mod;
        
        
        
    }
    int numRollsToTarget(int d, int f, int t) {
        memset(dp,-1,sizeof(dp));
        return ways(d,t,f) % mod;
    }
};

//or

#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;

    int numRollsToTarget(int d, int f, int t) {
        ll dp[d+1][t+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i <= min(d,t); i++){
            dp[i][i] = 1;
        }
        
        for(int i = 1; i <= d; i++){
            for(int j = 1; j <= t; j++){
                if(i == j)
                    continue;
                for(int k = 1; k <= f; k++){
                    if(j-k >= 0)
                        dp[i][j] = (dp[i][j] % mod + dp[i-1][j-k] % mod) % mod;
                }
            }
        }        

        return dp[d][t] % mod;
        
        
    }
};