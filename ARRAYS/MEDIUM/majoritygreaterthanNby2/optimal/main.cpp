// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int element;
//         int count = 0;
//         int cnt = 0;
//         int n = nums.size();
//         for(int i = 0 ; i < n ;i++){
//         if(count == 0){
//             count = 1;
//             element = nums[i];
//         }
//         else if(nums[i] == element) count++;
//         else count--;
//         }
//         for(int i = 0;i < n;i++){
//             if(element == nums[i]){
//                 cnt++;
//             }
//         }
//         if(cnt > n/2) return element;
//         return -1;
//     }
// };