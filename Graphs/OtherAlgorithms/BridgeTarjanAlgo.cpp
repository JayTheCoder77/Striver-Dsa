class Solution {
private:
    int timer = 1;

    void dfs(int node , int parent , vector<vector<int>> &adj , vector<vector<int>> &bridges , vector<int> &tin , vector<int> &low , vector<int> &vis){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        // dfs
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it , node , adj , bridges , tin , low , vis);
                low[node] = min(low[node] , low[it]);
                 
                // check if connection is critical or not (bridge)
                if(low[it] > tin[node]) bridges.push_back({it , node});
            }
            else{
                low[node] = min(low[node] , low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // create adj list
        vector<vector<int>> adj (n);
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // tarjan algorithm (dfs)
        vector<int> tin(n , 0); // time in (inserted)
        vector<int> low(n , 0); // lowest time apart from parent
        vector<int> vis(n , 0);
        vector<vector<int>> bridges;
        dfs(0 , -1 , adj , bridges , tin , low , vis);
        return bridges;
    }
};