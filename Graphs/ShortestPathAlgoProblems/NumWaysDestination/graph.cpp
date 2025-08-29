class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // create adj list
        
        vector<vector<pair<long long,long long>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        // dist and ways
        vector<long long> dist(n , LLONG_MAX);
        vector<long long> ways(n , 0);
        // pq min heap -> dist , node
        priority_queue <pair<long long,long long> , vector<pair<long long,long long>> , greater <pair<long long,long long>>> pq;
        int mod = 1e9 + 7;
        // start

        dist[0] = 0 , ways[0] = 1;
        pq.push({0 , 0});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long dis = it.first , node = it.second;

            if(dis > dist[node]) continue; // skip outdated entry

            for(auto it : adj[node]){
                long long edgeWt = it.second;
                long long adjNode = it.first;
                long long newDist = edgeWt + dis;
                // coming for the 1st time with a short distance
                if(newDist < dist[adjNode]){
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode] , adjNode});
                }
                else if(newDist == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};