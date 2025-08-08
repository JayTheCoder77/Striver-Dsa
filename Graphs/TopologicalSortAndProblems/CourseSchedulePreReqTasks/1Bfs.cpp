class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<vector<int>> adjList (N);
        for(auto it : prerequisites){
            adjList[it.first].push_back(it.second);
        }
        int indegree[N] = {0};
        for(int i = 0 ; i < N ; i++){
            for(auto it : adjList[i]) indegree[it]++;   
        }
        
        queue<int> q;
        for(int i = 0 ; i < N ; i++){
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
        if(topo.size() == N) return true;
        return false;
    }
};