class Solution {
public:
    void dfs(int node , vector<bool> &vis ,vector<vector<int>>& adj){
        vis[node] = true;
        for(int j = 0 ; j < adj.size(); j++){
            if(adj[node][j] && !vis[j]) dfs(j , vis , adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // adj matrix
        vector<bool> vis(n , false);
        vector<int> a;
        int cnt = 0;
        for(int i = 0 ; i <  isConnected.size() ; i++){ 
            if(!vis[i]){
                cnt++;
                dfs(i , vis ,isConnected); 
            }
        }
        return cnt;
    }
};

tc = o(n) + o(v + 2e)
sc = o(n) + o(n)
visited + recursive stack space