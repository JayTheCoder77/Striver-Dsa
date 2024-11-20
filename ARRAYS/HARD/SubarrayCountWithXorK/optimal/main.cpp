// #include <bits/stdc++.h>
// int Solution::solve(vector<int> &A, int B) {
//     map<int,int> firstXor;
//     firstXor[0] = 1;
//     int xor1 = 0 , count = 0;
//     for(int i = 0 ; i < A.size() ;i++){
//         xor1 = xor1 ^ A[i];
//         int x = xor1 ^ B;
//         if(firstXor.find(x) != firstXor.end()){
//             count += firstXor[x];
//             firstXor[xor1]++;
//         }
//         else{
//             firstXor[xor1]++;
//         }
//     }
//     return count;
// }

// tc = O(n logn)
// SC = o(n)