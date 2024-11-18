// #include<vector>

// vector<vector<int>> rotateMatrix(vector<vector<int>> &mat) {
// 	// Write your code here.
// 	int n = mat.size();
// 	int n1 = mat[0].size();
// 	vector<vector<int>> ans(n1, vector<int>(n));
// 	for(int i = 0 ; i < n;i++){
// 		for(int j = 0;j< n1;j++){
// 			ans[j][n-i-1] = mat[i][j];
// 		}
// 	}
// 	mat = ans;
// 	return ans;
// }