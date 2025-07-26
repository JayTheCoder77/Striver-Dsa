class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        // row , col , time
        queue<pair<pair<int, int>, int>> q;
        int cntFresh = 0;
        // push rotten
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i , j } ,0});
                    vis[i][j] = 2;
                }
                else vis[i][j] = 0; 
                // count fresh
                if(grid[i][j] == 1) cntFresh++;
            }
        }
        // delta row and col for navigation (clockwise row col values in array below)
        int delRow[] = {-1 , 0 , 1 , 0};
        int delCol[] = {0 , 1 , 0 , -1};
        int cnt = 0;
        int tm = 0;

        // bfs
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm , t);
            q.pop();
            // traverse neighbors
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                // check bounds , vis and if val is 1 or not
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    q.push({{nrow , ncol},t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        if(cnt != cntFresh) return -1;
        return tm;
    }
};

tc = o(nm + 4nm) = o(nm)
sc = o(n x m)