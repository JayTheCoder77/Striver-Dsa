
class Solution {
  public:
    void dfs(int node , vector<int> &vis,vector<int> adjList[]){
        vis[node] = 1;
        for(auto e : adjList[node]){
            if(!vis[e]){
            dfs(e , vis , adjList);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjList[V]; // 2d vector
        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V ; j++){
                if(adj[i][j] && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int> vis (V);
        for(int i = 0 ; i < V ;i++){
            if(!vis[i]){
                cnt++;
            dfs(i , vis , adjList);
            }
        }
        return cnt;
    }
};

tc = o(n) + o(v + 2e)
sc = o(n) + o(n)
visited + recursive stack space