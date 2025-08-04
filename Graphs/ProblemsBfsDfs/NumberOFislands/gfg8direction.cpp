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
            for(int i = -1 ; i <= 1 ; i++){
            for(int j = -1 ; j <= 1 ; j++){
                int nrow = r + i;
                int ncol = c + j;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 'L'){
                    q.push({nrow , ncol});
                    vis[nrow][ncol] = 1;
                }
            }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n , vector<int> (m , 0));
        int cnt = 0;
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == 'L' && !vis[row][col]){
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