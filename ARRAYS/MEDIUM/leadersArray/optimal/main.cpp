// class Solution {
//     // Function to find the leaders in the array.
//   public:
//     vector<int> leaders(vector<int>& arr) {
//         // Code here
//         vector<int> ans(0);
//         int maxI = INT_MIN;
//         int n = arr.size();
//         for(int i = n - 1 ; i >= 0 ; i--){
//             if(arr[i] >= maxI){
//             maxI = max(maxI, arr[i]);
//             }
//             else{
//                 continue;
//             }
//             ans.push_back(maxI);
//         }
//         std::reverse(ans.begin() , ans.end());
//         return ans;
//     }
// };