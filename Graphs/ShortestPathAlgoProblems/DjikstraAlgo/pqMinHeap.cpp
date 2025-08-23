// User Function Template
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
        
        priority_queue <pair<int,int> , vector <pair <int , int>> , greater<pair<int,int>>> pq; // min heap
        
        vector<int> dist(V , 1e9);
        
        // pq - dist , node
        dist[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto it : adj[node]){
                int edgeWt = it.second;
                int adjNode = it.first;
                
                if(dis + edgeWt < dist[adjNode]){
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode] , adjNode});
                }
            }
        }
        return dist;
    }
};

tc = o(elogv)
