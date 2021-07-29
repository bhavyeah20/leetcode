class Solution {
public:
    
    int match(vector<int> &student , vector<int> &mentor){
        int n = student.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(student[i] == mentor[i])
                ans++;
        }
        
        return ans;
    }
    
    void compatibility(int i, vector<vector<int>>& students, vector<vector<int>>& mentors, int ans, int &maxAns, vector<bool> &vis){
        if(i == students.size()){
            maxAns = max(maxAns, ans);
            return ;
        }
        
        for(int j = 0; j < mentors.size(); j++){
            if(!vis[j]){
                vis[j] = 1;
                ans += match(students[i], mentors[j]);

                compatibility(i+1,students,mentors,ans,maxAns,vis);
                
                ans -= match(students[i], mentors[j]);
                vis[j] = 0;
            } 
        }
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        vector<bool> vis(m,0);
        int maxAns = 0, ans = 0;
        compatibility(0,students,mentors,0,ans,vis);
        return ans;
    }
};