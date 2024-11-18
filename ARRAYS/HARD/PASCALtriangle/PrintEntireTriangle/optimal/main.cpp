// class Solution {
// public:
//     vector<int> generateRow(int row){
//         long long ans = 1;
//         vector <int> ansRow;
//         ansRow.push_back(1);
//         for(int i = 1; i < row; i++){
//             ans = ans * (row - i);
//             ans = ans / i;
//             ansRow.push_back(ans);
//         }
//         return ansRow;
//     }
//     vector<vector<int>> generate(int numRows) {
//         vector <vector<int>> pascalTriangle;
//         for(int i = 0 ; i < numRows ; i++){
//             pascalTriangle.push_back(generateRow(i+1));
//         }
//         return pascalTriangle;
//     }
// };