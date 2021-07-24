#define ll long long

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        unordered_set<int> seen;
        vector<vector<ll>> ans;
        vector<vector<ll>> points;
        for(auto segment: segments){
            points.push_back({segment[0], segment[2]});
            points.push_back({segment[1], segment[2]});
        }
        
        sort(points.begin(), points.end());
        
        ll prev = -1;
        ll sum = 0;
        for(auto point: points){
            auto i = point[0], color = point[1];
            if(prev != -1 && sum != 0 && prev != i){
                ans.push_back({prev, i, sum});
            }
            if(seen.count(color)){
                sum -= color;
            }
            
            else{
                seen.insert(color);
                sum += color;
            }
            
            prev = i;
        }
        
        return ans;
    }
};