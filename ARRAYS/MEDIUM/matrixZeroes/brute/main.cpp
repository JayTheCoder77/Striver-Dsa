// #include <bits/stdc++.h> 
// void markrow(int i, vector<vector<int>> &matrix ,int n , int m)
// {
// 	for(int j = 0 ; j < m; j++){
// 		if(matrix[i][j] != 0){
// 			matrix[i][j] = -1;
// 		}
// 	}	
// }
// void markcol(int j, vector<vector<int>> &matrix ,int n , int m) {

// 	for(int i = 0 ; i < n; i++){
// 		if(matrix[i][j] != 0){
// 			matrix[i][j] = -1;
// 		}
// 	}	
// }
// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
// 	// Write your code here.
// 	for(int i = 0 ; i < n ; i++){
// 		for(int j = 0 ; j < m ;j++){
// 			if(matrix[i][j] == 0){
// 				markrow(i , matrix , n , m);
// 				markcol(j , matrix , n , m);
// 			}
// 		}
// 	}
// 	for(int i = 0 ; i < n ; i++){
// 		for(int j = 0 ; j < m ;j++){
// 			if(matrix[i][j] == -1){
// 				matrix[i][j] = 0;
// 			}
// 		}
// 	}
// 	return matrix;
// }