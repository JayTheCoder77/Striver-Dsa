// optimal 2 using xor
//  int missingNumber(vector<int>& nums) {
//         //optimal 2 using XOR
//         int n = nums.size();
//         int xor1 = 0;
//         int xor2 = 0;
//         for(int  i = 0 ; i <= n - 1 ; i++){
//             xor2 = xor2 ^ nums[i];
//             xor1 = xor1 ^ (i + 1);
//             xor1 = xor1 ^ n;
//         }
//         return xor1 ^ xor2;
//     }






// optimal 1
        // int n = nums.size();
        // int sum = (n * (n + 1))/2;
        // int actualSum = 0;
        // for(int i = 0 ; i < n ; i++){
        //     actualSum = actualSum + nums[i];
        // }
        // return sum - actualSum;
