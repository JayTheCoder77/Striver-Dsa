// //better - using sort

// int longestSuccessiveElements(vector<int> &a) {
//     std::sort(a.begin(),a.end());
//     int longest = 1;
//     int currentCount = 0;
//     int last_Small = INT_MIN;
//     int n = a.size();
//     if(n == 0) return 0;
//     for(int i = 0 ; i < n ; i++){
//         if(a[i] - 1 == last_Small){
//             currentCount+= 1;
//             last_Small = a[i];
//         }
//         else if(last_Small != a[i]){
//             currentCount = 1;
//             last_Small = a[i];
//         }
//         longest = max(longest , currentCount);
//     }
//     return longest;
// }