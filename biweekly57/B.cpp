class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        map<pair<int,int>, int> omp; // what is ith pair 
        unordered_map<int,int> ump; //what is the end time at this pos;
        int n = times.size();
        for(int i = 0; i < n; i++){
            omp[{times[i][0], times[i][1]}] = i;
        }
        
        sort(times.begin(), times.end());
        
        for(auto timePair : times){
            for(int i = 0; i < n; i++){
                if(ump.find(i) == ump.end() || ump[i] <= timePair[0]){
                    ump[i] = timePair[1];
                    if(omp[{timePair[0], timePair[1]}] == targetFriend)
                        return i;
                    break;
                }
            }
        }
        
        return n-1;
    }
};