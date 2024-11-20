// int subarraysWithSumK(vector < int > a, int b) {
//     // Write your code here
//     int n = a.size();
//     int count = 0;
//     for(int i = 0 ; i < n ; i++){
//         int xor1 = 0;
//         for(int j = i ; j < n ; j++){
//             xor1 ^= a[j];
//             if(xor1 == b) count++;
//         }
//     }
//     return count;
// }

// TC = O(N2)
// SC = O(1)