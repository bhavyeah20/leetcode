class Solution {
public:
    
    unordered_set<string> dict;
    int dp[302];
    
    bool helper(string s, int i){
        
        if(i == s.length()){
            return true;
        }
        
        if(dp[i] != -1)
            return dp[i];
        
        for(int j = i; j < s.length(); j++){
            string curr = s.substr(i,j-i+1);
            if(dict.count(curr)){
                if(helper(s,j+1))
                    return dp[i] = true;
            }
        }
        
        return dp[i] = false;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        dict.clear();
        for(auto word: wordDict){
            dict.insert(word);
        }
        return helper(s,0);
        
        
    }
};