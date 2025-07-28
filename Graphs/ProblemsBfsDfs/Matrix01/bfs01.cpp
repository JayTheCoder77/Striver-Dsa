// this is leetcode version for finding nearest zeroes 
// if we wanna find nearest ones its simple this code willl work just change the if condition to be equal to one


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist (n , vector<int>(m , 0)); // ans
        vector<vector<int>> vis (n , vector<int>(m , 0));
        queue <pair< pair<int , int> , int>> q; // row , col , steps
        // mark all zeroes
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){                         // only this line will change for nearest ones ie : if(mat[i][j] == 1) rest code is same
                    q.push({{i , j} ,0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        // bfs
        int delRow [] = {-1 , 0 ,1 , 0};
        int delCol [] = {0 , 1 , 0 , -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;
            for(int i = 0 ; i < 4 ; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow , ncol} , steps + 1});
                }
            }
        }
        return dist;
    }
};

tc = o(n x m + 4 n x m) 
sc = o(3 n m )   