class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<int> prev(m , 0);  
        for(int i = 0 ; i < n ; i++){
            vector<int> cur(m , 0);
            for(int j = 0 ; j < m ; j++){
                int up = 1e9 , left = 1e9;
                if(i == 0 &&  j == 0){
                    cur[j] = grid[0][0];
                    continue;
                }
                else{
                if(i > 0) up = grid[i][j] + prev[j];
                if(j > 0) left = grid[i][j] + cur[j-1];
                cur[j] = min(up , left);
                }
            }
            prev = cur;
        }
        return prev[m-1];
    }
};