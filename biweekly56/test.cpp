class Solution {
public:
    //edge x,y,t
 
int cost[1002] = {0};
int Time[1002] = {0};

void djk(int src,int maxTime, vector<int> &passingFees, vector<vector<pair<int,int>>> &adjList){
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({cost[0],Time[0],0});  //costSoFar, TimeSoFar, src

    while(!pq.empty()){
        auto c = pq.top()[0], t = pq.top()[1], src = pq.top()[2];
        pq.pop();

        for(auto nbr : adjList[src]){ 

            if(t+nbr.second<=maxTime){

                if(cost[nbr.first] > c+passingFees[nbr.first]){
                    cost[nbr.first] = c + passingFees[nbr.first];
                    pq.push({cost[nbr.first],t+nbr.second,nbr.first});

                }

                else if(Time[nbr.first] > t+nbr.second){
                    Time[nbr.first] = t+nbr.second;
                    pq.push({c+passingFees[nbr.first],Time[nbr.first],nbr.first});
                }
            }
        }

    }


}
int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    int n = passingFees.size();
    for(int i = 0; i < n; i++){
        Time[i] = 1e9;
        cost[i] = 1e9;
    }

    vector<vector<pair<int,int>>> adjList(n);

    for(auto edge: edges){
        adjList[edge[0]].push_back({edge[1],edge[2]});
        adjList[edge[1]].push_back({edge[0],edge[2]});

    }
    cost[0] = passingFees[0], Time[0] = 0;
    djk(0,maxTime,passingFees,adjList);
    return cost[n-1] == 1e9 ? -1 : cost[n-1];
}


};