
class Solution {
  public:
    void dfs(int node , vector<int> adj[] , vector<bool> &visited , vector<int>& component){
        visited[node] = true;
        component.push_back(node);
        for(int neighbor : adj[node]){
            if(!visited[neighbor]) dfs(neighbor , adj , visited , component);
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        // create adj list
        vector<int> adj[V]; // 2d vector of size V
        for(auto &edge : edges){
            int u = edge[0] , v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // track visited
        vector<bool> visited(V , false);
        vector<vector<int>> components;
        
        // dfs on unvisited nodes
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                vector<int> component;
                dfs(i , adj , visited , component);
                components.push_back(component);
            }
        }
        return components;
    }
};
