class DisjointSet {
    vector<int> rank , parent , size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u , int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u , int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  private:
    bool isValid(int ar , int ac , int n , int m){
        return (ar >= 0 && ar < n && ac >= 0 && ac < m);
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> vis(n , vector<int>(m,0));
        vector<int> ans;
        int cnt = 0;
        DisjointSet ds(n * m);
        
        int delRow[] = {-1 , 0 , 1 , 0 };
        int delCol[] = { 0 , 1 , 0 , -1 };
        
        for(auto it : operators){
            int row = it[0] , col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            
            // check neighbors
            for(int i = 0 ; i < 4 ; i++){
                int adjRow = row + delRow[i];
                int adjCol = col + delCol[i];
                
                // check if valid
                if(isValid(adjRow , adjCol , n , m)){
                    // check if already an island
                    if(vis[adjRow][adjCol] == 1){
                        // finding exact number of component
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjRow * m + adjCol;
                        if(ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo)){
                            cnt--;
                            ds.unionBySize(nodeNo , adjNodeNo);
                        }
                    }
                }
            }
            // push cnt after main iteration
            ans.push_back(cnt);
        }
        
        return ans;
    }

    