class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // adj list
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        // queue djikstras algorithm - no need of pq here as the stops increase by +1
        // stops , node , dist
        queue <pair <int , pair<int,int> > > q;
        vector<int> dist(n , 1e9);
        q.push({0 , {src , 0}});
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto i : adj[node]){
                int adjNode = i.first;
                int edgeWt = i.second;

                if(edgeWt + cost < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + edgeWt;
                    q.push({stops + 1 , {adjNode , cost + edgeWt}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};