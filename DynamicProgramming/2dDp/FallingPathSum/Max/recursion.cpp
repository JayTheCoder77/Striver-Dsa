#include <bits/stdc++.h> 
int f(vector<vector<int>> &matrix , int i , int j){
    int n = matrix.size() , m = matrix[0].size();
    if(j < 0 || j > m-1) return -1e8;
    if(i == 0) return matrix[0][j];

    int s = matrix[i][j] + f(matrix , i-1 , j);
    int ld = matrix[i][j] + f(matrix , i-1 , j-1);
    int rd = matrix[i][j] + f(matrix , i-1 , j+1);

    return max(s , max(ld , rd));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size() , m = matrix[0].size();
    int maxi = -1e8;
    for(int j = 0 ; j < m ; j++){
        maxi = max(maxi ,  f(matrix , n-1 , j));
    }
    return maxi;
}

tc = o(3 ^ n) exponential
sc = o(n)