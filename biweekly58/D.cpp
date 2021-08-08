class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& A) {
        int n = A.size();
        vector<int> res(n);
        stack<int> s;
    
        
        for(int i = 0; i < n; i++){
            while(!s.empty() && A[s.top()] <= A[i]){
                res[s.top()]++;
                s.pop();
            }

            if(!s.empty()){
                res[s.top()]++;
            }

            s.push(i);
        }        
        
        return res;
        
        
    }
};