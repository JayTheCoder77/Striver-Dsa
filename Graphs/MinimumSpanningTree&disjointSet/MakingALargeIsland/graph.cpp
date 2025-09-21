class DisjointSet {
    public:
    vector<int> rank , parent , size;
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
    bool isValid(int row , int col , int n , int m){
        return row >= 0 && row < n && col >= 0 && col < m;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        DisjointSet ds(n * m);
        int delRow[] = {-1 , 0 , 1 , 0};
        int delCol[] = {0 , 1 , 0 , -1};
        // step 1 - connect all the components
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == 0) continue;
                for(int ind = 0 ; ind < 4 ; ind++){
                    int newr = row + delRow[ind];
                    int newc = col + delCol[ind];

                    if(isValid(newr , newc , n , m) && grid[newr][newc] == 1){
                        int nodeNo = row * n + col;
                        int newNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo , newNodeNo);
                    }
                }
            }
        }

        // step 2 - take every zero and try to convert to one
        int mx = 0; // max
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == 1) continue;
                set<int> components;
                for(int ind = 0 ; ind < 4 ; ind++){
                    int newr = row + delRow[ind];
                    int newc = col + delCol[ind];

                    if(isValid(newr , newc , n , m)){
                        if(grid[newr][newc] == 1){
                            components.insert(ds.findUParent(newr * n + newc));
                        }   
                    }
                }
                int sizeTotal = 0;
                for(auto i : components){
                    sizeTotal += ds.size[i];
                }
                mx = max(mx , sizeTotal + 1);
            }
        }
        // what if all the cells are ones
        for(int cellNo = 0 ; cellNo < n * m ; cellNo++){
            mx = max(mx , ds.size[ds.findUParent(cellNo)]);
        }
        return mx;
    }
};

tc = o(n2) approx.