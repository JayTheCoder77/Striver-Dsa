DIRECTED ACYCLIC GRAPH

class Solution {
    private:
    void dfs(int node , int vis[] , vector<vector<int>> &adjList , stack<int> &s){
        vis[node] = 1;

        for(auto e : adjList[node]){
            if(!vis[e]) dfs(e , vis , adjList , s);
        }
        s.push(node);
    }
    public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjList(V);
        stack <int> s;
        int vis[V];
        for(int i = 0 ; i < V ; i++) vis[i] = 0;
        for(auto e :    edges){
            int u = e[0] , v = e[1];
            adjList[u].push_back(v);
        }

        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i , vis , adjList , s);
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};