// User function Template for C++
class Solution {
  private:
    void topoSort(int node , vector<vector< pair<int,int> >> &adj , vector<int> &vis , stack<int> &st){
        vis[node] = 1;
        // we are using dfs topo sort here but bfs kahns can also be used
        for(auto i : adj[node]){
            int v = i.first;
            if(!vis[v]){
                topoSort(v , adj , vis , st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // create the adj list
        vector<vector< pair<int,int> >> adj(V);
        for(int i = 0 ; i< E ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v , wt});
        }
        
        // topo sort
        stack<int> st;
        vector<int> vis (V , 0);
        for(int i = 0 ; i <  V ; i++){
            if(!vis[i]){
                topoSort(i , adj , vis , st);
            }
        }
        
        // finding distances from source
        
        vector<int> dist (V , 1e9);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
                
            }
        }
        // Replace unreachable distances with -1
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};