// #include <bits/stdc++.h>
// vector<vector<int>> triplet(int n, vector<int> &arr)
// {
//     // Write your code here.
    
//     set <vector<int>> hash;
//     for(int i = 0 ; i < n ; i++){
//         for(int j = i + 1 ; j < n ; j++){
//             for(int k = j + 1 ; k < n ; k++){
//                 if(arr[i] + arr[j] + arr[k] == 0){
//                     vector <int> temp = {arr[i] , arr[j] , arr[k]};
//                     sort(temp.begin() , temp.end());
//                     hash.insert(temp);
//                 }
//             }
//         }
//     }
//     vector <vector<int>> ans(hash.begin() , hash.end());
//     return ans;
// }

// TC = 0(N^3 * LOG (NO OF UNIQUE ELEMENTS))
// SC = 2 * O( NO OF TRIPLETS )