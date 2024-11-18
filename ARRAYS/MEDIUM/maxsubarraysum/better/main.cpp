// #include <bits/stdc++.h>
// long long maxSubarraySum(std::vector<int> arr, int n) {
//     long long maxI = LLONG_MIN; // Start with the lowest value possible
//     for (int i = 0; i < n; i++) {
//         long long sum = 0;
//         for (int j = i; j < n; j++) {
//             sum += arr[j];
//             maxI = std::max(maxI, sum); // Update maxI to track the highest sum
//         }
//     }
//     return maxI;
// }
