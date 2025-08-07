class Solution {
  public:
  
    // bfs kahns algorithm topological sort
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjList(V);
        for(auto e : edges){
            int u = e[0] , v = e[1];
            adjList[u].push_back(v);
        }
        int indegree[V] = {0};
        for(int i = 0 ; i < V ; i++){
            for(auto it : adjList[i]) indegree[it]++;   
        }
        
        queue<int> q;
        for(int i = 0 ; i < V ; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            // node is in topo sort so we remove it from indegree;
            for(auto it : adjList[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }
};

tc = o(v + e)