class Solution {
public:
    
    int dp[101];
    
    int ways(int i, string s){
        
        if(i >= s.size())
            return 1;
        
        if(s[i] == '0' && i-1 >= 0 && s[i-1] != '1' && s[i-1] != '2')
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int ways1 = 0, ways2 = 0;
        if(s[i] >= '1' && s[i] <= '9'){
            ways1 = ways(i+1,s);
        }
        
        if(i+1 < s.size() && (s[i] == '1' && s[i+1] <= '9' && s[i+1] >= '0') || (s[i] == '2' && s[i+1] <= '6' && s[i+1] >= '0')){
            ways2 = ways(i+2,s);
        }
        
        return dp[i] =  ways1 + ways2;
        
    }
    
    
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return ways(0,s);
    }
};

//or
class Solution {
public:
    
    int numDecodings(string s) {
        int n = s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));

        dp[n] = 1;
        
        for(int i = n-1; i >= 0; i--){

            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }

            if(i+1 <= n)
                dp[i] += dp[i+1];

            if(i+2 <= n && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
                dp[i] += dp[i+2];
        }

        return dp[0];
    }
};