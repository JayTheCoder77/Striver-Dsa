#include <bits/stdc++.h> 
int f(int i , int j1 , int j2 , vector<vector<int>> &grid){
    int r = grid.size() , c = grid[0].size();
    int maxi = -1e8;
    if(j1 < 0 || j1 > c-1 || j2 < 0 || j2 > c-1) return -1e8;
    if(i == r -1 ){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    int dj[] = {-1 , 0 , 1};
    for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
        for(int dj2 = -1 ; dj2 <= 1 ; dj2++){
            if(j1 == j2) maxi = max(maxi , grid[i][j1] + f(i+1 , j1 + dj1 , j2 + dj2 , grid));
            else maxi = max(maxi , grid[i][j1] + grid[i][j2] + f(i+1 , j1 + dj1 , j2 + dj2 , grid));
        }
    }
    return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return f(0,0,c-1,grid);
}

tc = o(3^r x 3^r) exponential
sc = o(r)