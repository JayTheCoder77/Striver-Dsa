
// o n3

// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     // Write your code here - brute
//     int len = 0;
//     for(int  i = 0 ; i < a.size() ; i++){
//         for (int j = i ; j < a.size() ; j++){
//             int sum = 0 ;
//             for(int m = i ;m <= j ; m++){
//                 sum += a[m];
//             }
//             if(sum == k){
//                 len = max(len , j - i + 1);
//             }
//         }
//     }
//     return len;
// }




// o n2

// int longestSubarrayWithSumK(vector<int> a, long long k) {
//     //better
//     int len = 0;
//     for(int  i = 0 ; i < a.size() ; i++){
//             int sum = 0 ;
//         for (int j = i ; j < a.size() ; j++){
//             sum += a[j];
//             if(sum == k){
//                 len = max(len , j - i + 1);
//                    }
//             }
//     }
//     return len;
// }