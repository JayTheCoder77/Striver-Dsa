// #include <bits/stdc++.h>
// long long maxSubarraySum(vector<int> arr, int n)
// {
//     // Write your code here - brute
//     long long maxI = LLONG_MIN;
//     for(int i = 0 ; i < n ; i++){

//         for(int j = i ; j < n ; j++){
        
//         long long sum = 0;

//             for(int k = i ; k <= j ;k++){

//                 sum += arr[k];
//                 maxI = std::max(maxI , sum);
//             }

//         }

//     }
//     return maxI;
// }