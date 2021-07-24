class Solution {
public:
    bool areOccurrencesEqual(string s) {
    
        unordered_map<int,int> mp;
        
        for(auto ch: s){
            mp[ch-'a']++;
        }
        
        int prev = 0;
        auto it = mp.begin();
        while(it != mp.end()){
            if(it == mp.begin()){
                prev = it->second;
            }
            
            else{
                if(it->second != prev)
                    return false;
            }
            
            it++;
        }
        
        return true;
    }
};