class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m,0));
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        int moves = 0;
        
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = 1;
        
        while(!q.empty()){
            
            int sz = q.size();
            moves++;
            for(int z = 0; z < sz; z++){
            int x = q.front().first, y = q.front().second;
            q.pop();
            
            
            
            for(int k = 0; k < 4; k++){
                int i = x + dx[k], j = y + dy[k];
                
                if(i >= 0 && i < n && j >= 0 && j < m){
                    if(!vis[i][j] && maze[i][j] == '.'){
                        q.push({i,j});
                        vis[i][j] = 1;
                        
                        if(i == 0 || j == 0 || i == n-1 || j == m-1)
                            return moves;
                    }
                }
            }
        }
        }
        
        return -1;
        
    }
};