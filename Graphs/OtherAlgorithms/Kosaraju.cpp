    class Solution {
      private:
        void dfs(int node , vector<vector<int>> &adj , vector<int> &vis , stack<int> &st){
            vis[node] = 1;
            
            for(auto it : adj[node]){
                if(!vis[it]) dfs(it , adj , vis , st);
            }
            st.push(node);
        }
        
        void dfs3(int node , vector<vector<int>> &adjT , vector<int> &vis){
            vis[node] = 1;
            for(auto it : adjT[node]){
                if(!vis[it]) dfs3(it , adjT , vis);
            }
        }
        
      public:
        int kosaraju(vector<vector<int>> &adj) {
            int n = adj.size();      
            vector<int> vis(n , 0);        
            stack<int> st;
            
            // dfs - 1 and storing nodes according to finishing time
            for(int i = 0 ; i < n ; i++){
                if(!vis[i]) dfs(i , adj , vis , st);
            }
            
            // reverse the graph (transpose)
            vector<vector<int>> adjT(n);
            for(int i = 0 ; i < n ; i++){
                // reset the vis for dfs again
                vis[i] = 0;
                for(auto it : adj[i]){
                    adjT[it].push_back(i);
                }
            }
            
            // finding the scc's (Strongly connected components) using dfs on the reversed graph
            int scc = 0;
            while(!st.empty()){
                int node = st.top();
                st.pop();
                if(!vis[node]){
                    scc++;
                    dfs3(node , adjT , vis);    
                } 
            }
            return scc;
        }
    };