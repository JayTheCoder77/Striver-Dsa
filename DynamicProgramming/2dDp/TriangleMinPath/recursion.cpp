#include <bits/stdc++.h> 
int f(int i , int j , vector<vector<int>>& triangle, int n){
	if(i == n-1) return triangle[n-1][j];
	int down = 0  , downright = 0;

	down = triangle[i][j] + f(i+1 , j , triangle , n);
	downright = triangle[i][j] + f(i+1 , j+1 , triangle , n);

	return min(down , downright);

}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	return f(0 , 0 ,triangle, n);
}

tc = o( 2 ^ (summation of rows))
sc = o(n)