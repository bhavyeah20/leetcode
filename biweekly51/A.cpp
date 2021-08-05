class Solution {
public:
    string replaceDigits(string s) {
        for(int i = 0; i < s.size(); i++){
            if(i&1){
                s[i] = s[i-1]+(s[i]-'0');
            }
        }
        return s;
        
    }
};