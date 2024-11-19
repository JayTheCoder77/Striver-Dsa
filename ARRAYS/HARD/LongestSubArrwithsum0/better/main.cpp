// class Solution {
//   public:
//     int maxLen(vector<int>& arr) {
//         // code here
//         int maxL = 0;
//         int n = arr.size();
//         for(int i = 0 ; i < n ; i++){
//                 int sum = 0;
//             for(int j = i ; j < n ; j++){
//                 sum += arr[j];
            
//                     if(sum == 0){
//                         maxL = std::max(maxL , j - i + 1 );
//                     }
//             }
//                 }
            
//         return maxL;
//     }
// };

// tc = o(n2)
// sc = o(1)