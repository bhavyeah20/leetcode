class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        
        int curr = 0;
        int ans = 0;
        
        for(int i = 0; i < rungs.size(); i++){
            if(curr + dist < rungs[i]){
                int num = (rungs[i]-curr-1)/dist;
                ans += num;
                i--;
                curr += num*dist;
            }
            
            else{
                curr = rungs[i];
            }
        }
        
        return ans;
        
    }
};