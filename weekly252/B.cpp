class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        priority_queue<long long> pq;
        long long cnt = 0, prev = -1;
        for(auto it: milestones){
            pq.push(it);
        }
        
        
        while(!pq.empty()){
            long long top = pq.top();
            cnt++;
            pq.pop();
            if(prev > 0)
                pq.push(prev);
            prev = top-1;
        }
        
        
        return cnt;
            
    }
};