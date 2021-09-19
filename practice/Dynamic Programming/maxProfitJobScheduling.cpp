class Solution {
public:
    
    unordered_map<int,int> dp;
    
    int find(vector<vector<int>> &jobs, int currEnd){

        int s = 0, e = jobs.size()-1;
        int mid = (s + e)/ 2;

        while(s <= e){
            mid = (s + e)/ 2;

            if(jobs[mid][0] == currEnd){
                return mid;
            }

            else if(jobs[mid][0] < currEnd){
                s = mid+1;
            }

            else 
                e = mid-1;
        }

        return s;

}

    int gain(int i, vector<vector<int>> &jobs){
        if(i >= jobs.size())
            return 0;
        
        if(dp.find(i) != dp.end())
            return dp[i];
        
        int j = find(jobs,jobs[i][1]);
                
        return dp[i] = max(jobs[i][2] + gain(j,jobs), gain(i+1,jobs));
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        dp.clear();
        return gain(0,jobs);
    }
};