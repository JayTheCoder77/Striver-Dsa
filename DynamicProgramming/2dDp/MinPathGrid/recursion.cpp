#include <bits/stdc++.h> 
int f(vector<vector<int>> &grid , int i , int j){
    if(i == 0 && j == 0) return grid[0][0];
    if(i < 0 || j < 0) return 1e9;

    int up = grid[i][j] + f(grid , i-1 , j);
    int left = grid[i][j] + f(grid , i , j-1);
    return min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size() , m = grid[0].size();
    return f(grid , n-1 , m-1);
}