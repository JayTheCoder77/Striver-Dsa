class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> prev(m ,0);
    for(int i = 0 ; i < n ; i++){
        vector<int> cur(m,0);
        for(int j = 0 ; j < m ; j++){
            int up = 0 , left = 0;
            if(obstacleGrid[i][j] == 1){
                cur[j] = 0;
                continue;
            }
            else if(i == 0 && j == 0){
                cur[j] = 1;
                continue;
            }
            else{
                if(i > 0) up = prev[j];
                if(j > 0) left = cur[j-1];
            }
            cur[j] = up + left;
        }
        prev = cur;
    }
    return prev[m-1];
    }
};