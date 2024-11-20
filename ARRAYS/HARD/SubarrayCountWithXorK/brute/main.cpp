// int subarraysWithSumK(vector < int > a, int b) {
//     // Write your code here
//     int n = a.size();
//     int count = 0;
//     for(int i = 0 ; i < n ; i++){
//         for(int j = i ; j < n ; j++){
//             int xor1 = 0;
//             for(int k = i ; k <= j ; k++){
//                 xor1 = xor1 ^ a[k];
//             }
//             if(xor1 == b) count++;
//         }
//     }
//     return count;
// }

// TC = O(N3)
// SC = O(1)