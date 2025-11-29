#include <bits/stdc++.h> 
int f(vector<vector<int>> &matrix , int i , int j , int n){
    if(j < 0 || j >= n) return 1e8;
    if(i == 0) return matrix[0][j];

    int s = matrix[i][j] + f(matrix , i-1 , j , n);
    int ld = matrix[i][j] + f(matrix , i-1 , j-1 , n);
    int rd = matrix[i][j] + f(matrix , i-1 , j+1 , n);

    return min(s , min(ld , rd));
}
int minFallingPathSum(vector<vector<int>> &matrix, int n) {
    int mini = 1e8;
    for(int j = 0 ; j < n ; j++){
        mini = min(mini ,  f(matrix , n-1 , j , n));
    }
    return mini;
}