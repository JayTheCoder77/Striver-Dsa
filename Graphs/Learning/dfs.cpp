class Solution {
  public:
    void DFS(int node , vector<bool> &vis , vector<vector<int>>& adj , vector<int> &ls){
        vis[node] = true;
        ls.push_back(node);
        for(auto i : adj[node]){
            if(!vis[i]) DFS(i , vis,adj ,ls);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> visited (n);
        int start = 0;
        vector<int> ls;
        DFS(start ,  visited , adj, ls);
        return ls;
    }
};

tc = o(2e * n) undirected graph
e = edges
sc = o(n)