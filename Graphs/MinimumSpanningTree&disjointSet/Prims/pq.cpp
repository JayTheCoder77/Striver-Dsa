class Solution {
  public:
    // PRIMS ALGORITHM - greedy intuition
    int spanningTree(int V, vector<vector<int>>& edges) {
        // create adj list
        vector<vector<pair<int, int >>> adj (V);
        for(auto e : edges){
            adj[e[0]].push_back({e[1] , e[2]});
            adj[e[1]].push_back({e[0] , e[2]});
        }
        
        // min heap
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> vis (V , 0);
        
        // weight , node
        // parent only req when asked to return the mst too
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            for(auto it : adj[node]){
                int edgeWt = it.second;
                int adjNode = it.first;
                
                if(!vis[adjNode]) pq.push({edgeWt , adjNode});
            }
        }
        return sum;
    }
};

tc = o(e log e)
sc = o(e)