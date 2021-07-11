class Solution {
public:
    bool sumGame(string s) {
        int n = s.size();
        
        int diff = 0, cnt = 0;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '?'){
                if(i < n/2) cnt++;
                
                else cnt--;
            }
            
            else{
                if(i < n/2) diff += s[i]-'0';
                
                else diff -= s[i]-'0';
            }
        }
        
        return !(diff * 2 == -cnt * 9);
    }
};