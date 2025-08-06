if cycle exists return true
class Solution {
private:
    bool dfs(int node , vector<vector<int>> &graph , int vis[] , int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto e : graph[node]){
            // if not visited
            if(!vis[e]){
                if(dfs(e , graph , vis , pathVis)) return true;
            }
            else if(pathVis[e]){
                return true;
            }
        }   
        pathVis[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> graph(V);
        int vis [V];
        int pathVis [V];
        for(int i = 0 ; i < V ; i++){
            vis[i] = 0;
            pathVis[i] = 0;
        }
        for (auto edge : edges) {
            int u = edge[1];
            int v = edge[0];
            graph[u].push_back(v);
        }
        // connected components case

        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(dfs(i , graph , vis , pathVis)) return true;
            }
        }
        return false;
    }
};
