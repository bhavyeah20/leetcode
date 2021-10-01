class Solution {
public:
    
    void lcs(string &s, vector<int> &pi){
        int n = s.size();
        int j = 0;
        
        for(int i = 1; i < n; i++){
            j = pi[i-1];
            while(j > 0 && s[i] != s[j]){
                j = pi[j-1];
            }
            
            if(s[i] == s[j]){
                j++;
                pi[i] = j;
            }
        }
    }
    
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        
        if(!n)
            return 0;
        
        if(!m)
            return -1;
        
        vector<int> pi(n,0);
        
        lcs(needle,pi);
        
        int i = 0, j = 0;
        while(i < m && j < n){
            while(j > 0 && haystack[i] != needle[j]){
                j = pi[j-1];
            }
            
            if(haystack[i] == needle[j]){
                j++;
            }
            
       
            i++;
            
            if(j == n){
                return i-j;
            }
            


        }
        
        return -1;
    }
};