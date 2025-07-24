class Solution {
  public:
        // same code will work for directed and undirected
        vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<int> vis (n , 0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> BFS;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            BFS.push_back(node);
            
            for(auto i : adj[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i);  
                } 
            }
        }
        return BFS;
    }
};

tc = o(n * 2E) 
2e - for loop
n - queue while loop
sc = o(3n) approx o(n)