#include <bits/stdc++.h> 
  // if i,j == -1 then its a dead cell coding ninjas
int f(int i , int j, vector< vector< int> > &mat){
    if(i >= 0 && j >= 0 && mat[i][j] == -1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    int up = f(i-1 , j,mat);
    int left = f(i, j-1,mat);

    return up + left;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
	return f(n-1,m-1,mat);
}
