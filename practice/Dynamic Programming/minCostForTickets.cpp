class Solution {
public:
    
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int dp[366] = {0};
        unordered_set<int> travelDays;
        for(auto day: days)
            travelDays.insert(day);
        
        for(int i = 1; i < 366; i++){
            if(!travelDays.count(i))
                dp[i] = dp[i-1];
            
            else{
                dp[i] = min({dp[i-1] + cost[0], dp[max(i-7,0)] + cost[1], dp[max(i-30,0)] + cost[2]});
            }
                
        }        
        
        return dp[365];
    }
};

//or

class Solution {
public:
    
    int dp[4][366][366];
    
    int validity[4];
    unordered_set<int> travelDays;
    int cost(int day, int lastBuy, int pass, vector<int> &costs){
        if(day == 366)
            return 0;
        
        if(dp[pass][day][lastBuy] != -1)
            return dp[pass][day][lastBuy];
        
        if(!travelDays.count(day))
            return cost(day+1,lastBuy,pass,costs);
        
        if(day < lastBuy + validity[pass]){
            return dp[pass][day][lastBuy] = cost(day+1, lastBuy, pass, costs);
        }
        
        else{
            int cost1 = costs[0] + cost(day+1,day,1,costs);
            int cost2 = costs[1] + cost(day+1,day,2,costs);
            int cost3 = costs[2] + cost(day+1,day,3,costs);
            
            return dp[pass][day][lastBuy] = min({cost1, cost2, cost3});
        }
        
    }
        
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        validity[0] = 0;
        validity[1] = 1;
        validity[2] = 7;
        validity[3] = 30;
        
        for(auto day: days)
            travelDays.insert(day);
        
        memset(dp,-1,sizeof(dp));
    
        return cost(1,0,0,costs);
        
    }
};
