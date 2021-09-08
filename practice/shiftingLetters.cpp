class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i = s.length() - 1; i >=0; i--){
            if(i != s.length()-1)
                shifts[i] += shifts[i+1] % 26;
            
            s[i] = 'a' + (((s[i]-'a') + shifts[i]) % 26);
        }
        
        return s;
    }
};