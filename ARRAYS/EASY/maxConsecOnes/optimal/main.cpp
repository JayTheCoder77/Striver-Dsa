// int findMaxConsecutiveOnes(vector<int>& nums) {
//         int count = 0;
//         int maxCon = 0;
//         int n = nums.size();
//         for(int i = 0 ;i <n ; i++){
//             if(nums[i] == 1){
//                 count++;
//                 maxCon = max(maxCon , count);
//             }
//             if(nums[i] == 0){
//                 count = 0;
//             }
//         }
//         return maxCon;
//     }