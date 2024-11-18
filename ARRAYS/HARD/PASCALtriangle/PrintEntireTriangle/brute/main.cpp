// int nCr (int n , int r){
//     int res = 1;
//     for (int i = 0; i < r; i++)
//     {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return res;
// }

// vector<vector<int>> pascalTriangle(int N) {
//     // Write your code here.
//     vector <vector <int>> ans;
//     for(int i = 0 ; i < N ; i++){
//     vector <int> tempList;
//         for(int j = 0;j <= i ;j++){
//             tempList.push_back(nCr(i,j));
//         }
//         ans.push_back(tempList);
//     }
//     return ans;
// }