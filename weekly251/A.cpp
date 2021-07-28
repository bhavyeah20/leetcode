class Solution {
public:
    int getLucky(string s, int k) {
        string s2 = "";
        for(auto ch: s){
            string t = to_string((ch-'a')+1);
            s2 += t;
        }
            
        long long sum = 0;
        while(k--){
            sum = 0;
            for(auto ch: s2){
                sum += (ch-'0');
            }
            
            s2 = to_string(sum);
        }
        
        return sum;
    }
};