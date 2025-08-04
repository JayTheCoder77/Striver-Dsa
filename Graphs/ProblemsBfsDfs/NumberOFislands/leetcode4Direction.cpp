class Solution {
public:
    void bfs(int row , int col ,vector<vector<char>>& grid , vector<vector<int>>& vis){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row , col});
        
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // traverse neighbors
            int delRow[] = {-1 , 0 , 1, 0};
            int delCol[] = {0 , 1 , 0 ,-1};
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    q.push({nrow , ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n , vector<int> (m , 0));
        int cnt = 0;
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == '1' && !vis[row][col]){
                    cnt++;
                    bfs(row , col , grid , vis);
                }
            }
        }
        return cnt;
    }
};


tc = o(n2)
sc = o(n2)