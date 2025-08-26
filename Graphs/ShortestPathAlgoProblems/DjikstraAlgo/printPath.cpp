class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
 
        // making the adj list
        vector<vector<pair<int,int>>> adj(n+1);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue <pair<int,int> , vector <pair <int , int>> , greater<pair<int,int>>> pq; // min heap
        
        vector<int> dist(n + 1 , 1e9) , parent(n+1);
        for(int i = 1 ; i <= n ; i++) parent[i] = i;
        
        dist[1] = 0;
        pq.push({0 , 1});
        
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            
            for(auto i : adj[node]){
                int edgeWt = i.second;
                int adjNode = i.first;
                
                if(edgeWt + dis < dist[adjNode]){
                    dist[adjNode] = edgeWt + dis;
                    pq.push({dist[adjNode] , adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        vector<int> path;
        int node = n;
        while (node != parent[node]) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        // Compute path weight (to satisfy checker)
        int totalWeight = 0;
        for (int i = 1; i < path.size(); i++) {
            int u = path[i - 1], v = path[i];
            for (auto& p : adj[u]) {
                if (p.first == v) {
                    totalWeight += p.second;
                    break;
                }
            }
        }

        path.insert(path.begin(), totalWeight);
        return path;
    }
};

tc = o(elogv + n)
