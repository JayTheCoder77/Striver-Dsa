class Solution {
public:
    // odd length of cycles cannot be a bipartite graph
    bool dfs(int node , int col , int color[] , vector<vector<int>>& graph){
        color[node] = col;
        for(auto e : graph[node]){
            if(color[e] == -1){
                if(!dfs(e , !col , color , graph)) return false;
            }
            else if (color[e] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color [V];

        for(int i = 0 ; i < V ; i++) color[i] = -1;

        for(int i = 0 ; i < V ; i++){
            if(color[i] == -1)
                if(!dfs(i , 0 , color , graph)) return false;
        }
        return true;
    }
};

tc = o(v + 2e)
sc = o(v + 2e)