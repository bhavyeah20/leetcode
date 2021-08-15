class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(auto str: patterns){
            int j = 0;
            int atmpt = 0;
            for(int i = atmpt; i < word.size(); i++){
                while(i < word.size() && j < str.size() && word[i] == str[j]){
                    i++;
                    j++;
                }
                
                if(j == str.size()){
                    cnt++;
                    break;
                }
                
                else{
                    j = 0;
                    atmpt++;
                    i = atmpt-1;
                }
            }
            

        
        }
        
        return cnt;
        
    }
};