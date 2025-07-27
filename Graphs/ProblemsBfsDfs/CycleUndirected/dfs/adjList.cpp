class Solution {
  public:
    bool dfs(int node , int parent , int vis[] , vector<vector<int>> &adj){
        vis[node] = 1;
        for(auto e : adj[node]){
            if(!vis[e]){
                if(dfs(e , node , vis ,adj)) return true;
            }
            else if(vis[e] && e != parent) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        // adj list from edge matrix
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // handles connected components case
        int vis[V] = {0};
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(dfs(i , - 1 , vis , adj)) return true;
            }
        }
        return false;
    }
};