class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,1e5);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i], 1 + dp[i-j*j]);
            }
        }
        

        return dp[n];
    
    }
};


//or

class Solution {
public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        for(int i = 1; i*i <= n; i++){
            perfectSquares.push_back(i*i);
        }
        
        vector<int> cnt(n+1,0);
        if(perfectSquares.back() == n)
            return 1;
        
        queue<int> q;
        q.push(0);
        
        int currCount = 0;
        
        while(!q.empty()){
            int sz = q.size();
            currCount++;
            
            for(int i = 0; i < sz; i++){
                int curr = q.front();
                q.pop();
                
                for(auto sq: perfectSquares){
                    if(curr + sq == n)
                        return currCount;
                    
                    else if(curr + sq < n && cnt[curr+sq] == 0){
                        q.push(curr+sq);
                        cnt[curr+sq] = currCount;
                    }
                    
                    else if(curr + sq > n)
                        break;
                }
            }
        }
        
        return currCount;
        
        
    }
};