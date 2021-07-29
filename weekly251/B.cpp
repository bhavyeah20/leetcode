class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool mut = 0;    
        for(auto &ch : num){
            if(change[ch-'0'] > ch-'0'){
                mut = 1;
                ch = change[ch-'0']+'0';
            }
            
            else if(ch-'0' != change[ch-'0'] && mut)
                break;
        }
        
        return num;
    }
};