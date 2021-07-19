struct TrieNode{
    TrieNode *child[2];
    int go;

    TrieNode(){
        this->child[0] = NULL;
        this->child[1] = NULL;
        go = 0;
    }

    void insert(int root, int d){
        TrieNode *curr = this;
        for(int i = 17; i >= 0; i--){
            int bit = (root >> i) & 1;
            if(curr->child[bit] == NULL) curr->child[bit] = new TrieNode();
            curr = curr->child[bit];
            curr->go += d;
        }
    }

    int findMax(int root){
        TrieNode *curr = this;
        int res = 0;
        for(int i = 17; i >= 0; i--){
            int bit = ((root >> i) & 1);
            if(curr->child[1-bit] && (curr->child[1-bit])->go > 0){
                curr = curr->child[1-bit];
                res |= (1<<i);
            }
            else{
                curr = curr->child[bit];
            }
        }

        return res;
    }
};


class Solution {
public:

    TrieNode *head = new TrieNode();

    void dfs(int root,vector<vector<int>> &graph, vector<vector<pair<int,int>>> &query, vector<int> &ans){
        head->insert(root,1);
        for(auto q : query[root]){
            ans[q.second] = head->findMax(q.first);
        }

        for(auto nbr: graph[root]){
            dfs(nbr, graph, query, ans);
        }

        head->insert(root,-1);
    }

    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        //query -> node , val
        vector<vector<int>> graph(parents.size());
        int root;
        for(int i = 0; i < parents.size(); i++){
            if(parents[i] == -1)
                root = i;

            else
                graph[parents[i]].push_back(i);
        }

        vector<int> ans(queries.size());
        vector<vector<pair<int,int>>> query(parents.size()); // node -> vector{val,i}    
    
        for(int i = 0; i < queries.size(); i++){
            query[queries[i][0]].push_back({queries[i][1],i});
        }

        dfs(root, graph, query,ans);

        return ans;
    }
};
