// #include <bits/stdc++.h> 
// int getLongestSubarray(vector<int>& nums, int k){
//     // Write your code hereint 
//     map<long long, int> preSumMap;
//     long long sum = 0;
//     int maxLen = 0;

//     for (int i = 0; i < nums.size(); i++) {
//         sum += nums[i];
        
//         // If the sum equals k, update maxLen
//         if (sum == k) {
//             maxLen = max(maxLen, i + 1);
//         }
        
//         long long rem = sum - k;
        
//         // If the remainder is found in the map, update maxLen
//         if (preSumMap.find(rem) != preSumMap.end()) {
//             int len = i - preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }

//         // If sum is not in the map, store it with the current index
//         if (preSumMap.find(sum) == preSumMap.end()) {
//             preSumMap[sum] = i;
//         }
//     }

//     return maxLen;
// }
