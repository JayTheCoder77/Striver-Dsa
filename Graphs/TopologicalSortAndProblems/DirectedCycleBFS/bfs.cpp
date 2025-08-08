class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
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
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            // node is in topo sort so we remove it from indegree;
            for(auto it : adjList[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return cnt == V ? false : true;
    }
};