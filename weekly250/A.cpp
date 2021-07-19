class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,bool> s;
        
        int total = 0, cnt = 0;
        
        for(int i = 0; i < brokenLetters.size(); i++){
            s[brokenLetters[i]] = 1;
        }
        
        int n = text.length();
        int i = 0;
        for(int i = 0; i < n; i++){
            cnt = 0;
            while(i < n && text[i] != ' '){
                if(s.find(text[i]) != s.end()){
                    cnt++;
                }
                
                i++;
            }
            
            if(cnt == 0)
                total++;

        }
        
        return total;
    }
};