class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create adj list
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1] , it[2]});
        }
        vector<int> time (n + 1 , 1e9);
        // k = source
        // min heap - time , node
        priority_queue< pair<int,int> , vector <pair<int,int>> , greater < pair<int,int>> > pq;
        time[k] = 0;
        pq.push({0 , k});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int t = it.first;
            int node = it.second;

            if(t > time[node]) continue;
        
            for(auto i : adj[node]){
                int adjNode = i.first;
                int edgeWt = i.second;

                if(edgeWt + t < time[adjNode]){
                    time[adjNode] = edgeWt + t;
                    pq.push({time[adjNode] , adjNode});
                }
            }
        }
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            if(time[i] == 1e9) return -1; // unreachable
            ans = max(ans , time[i]);
        }
        return ans;
    }
};