#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl "\n" 


    unordered_map<string, int> mp;
    
    int cost(vector<int> &days, int i, vector<int> &costs, int one, int seven, int thirty){
        if(i == days.size())
            return 0;
        
        string s = to_string(one) + "$" + to_string(seven) + "$" + to_string(thirty);
        if(mp.find(s) != mp.end())
            return mp[s];
        
        int cost1 = INT_MAX-1;
        int cost2 = cost1, cost3 = cost1;
        
           
        if(days[i] >= thirty){
            cost3 = costs[2] + cost(days, i+1,costs, one, seven, 30 + days[i]);
        }
        
        else 
            cost3 = cost(days, i+1,costs, one, seven, thirty);

        
        if(days[i] >= seven){
            cost2 = costs[1] + cost(days, i+1,costs, one, 7 + days[i], thirty);
        }
        
        else
            cost2 = cost(days, i+1,costs, one, seven, thirty);

        
        if(days[i] >= one){
            cost1 = costs[0] + cost(days, i+1,costs, 1 + days[i], seven, thirty);
        }
        
        else
            cost1 = cost(days, i+1,costs, one, seven, thirty);
     
        
        return mp[s] = min({cost1, cost2, cost3});
    }
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        mp.clear();
        return cost(days,0,costs,0,0,0);
    }


int main(){


	vector<int> days({1,4,6,7,8,20});
	vector<int> costs({2,7,15});
	cout<<mincostTickets(days,costs);


}