class Solution {
  public:
    bool bfsDetect(int src , int vis[] , vector<vector<int>> &adjList){
        vis[src] = 1;
        queue <pair <int , int >> q;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto e : adjList[node]){
                if(!vis[e]){
                    vis[e] = 1;
                    q.push({e , node});
                }
                else if(parent != e) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int vis[V] = {0};
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(bfsDetect(i , vis , adj)) return true;
            }
        }
        return false;
    }
};

tc = o(n + 2e) not calling for every iteration so  n + 2e and not n * 2e
sc = o(n) + o(n) = approx o(n)