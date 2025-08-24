class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // making the adj list
        vector<vector<pair<int,int>>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        set<pair<int,int>> st;
        vector<int> dist(V ,1e9);

        st.insert({0,src});
        dist[src] = 0;

        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;

            st.erase(it);

            for(auto it : adj[node]){
                int edgeWt = it.second;
                int adjNode = it.first;

                if(dis + edgeWt < dist[adjNode]){
                    if(dist[adjNode] != 1e9) st.erase({dist[adjNode] , adjNode});
                    dist[adjNode] = dis + edgeWt;
                    st.insert({dist[adjNode] , adjNode});
                }
            }
        }
        return dist;
    }
};

tc = o(elogv)
