//  int lenOfLongSubarr(int a[],  int n, int k) 
//     { 
//         // Complete the function
//         int left = 0;
//         int right = 0;
//         long long sum = a[0];
//         int maxLen = 0;
//         while(right < n){
//             right++;
//             if(right < n){
//                 sum += a[right];
//             }
//             if(sum == k){
//                 maxLen = max(maxLen , right - left + 1);
//             }
//             while(left <= right && sum > k){
//                 sum -= a[left];
//                 left++;
//             }
//         }
//         return maxLen;
//     } 