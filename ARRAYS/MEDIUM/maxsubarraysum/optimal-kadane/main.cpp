// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxI = INT_MIN , sum = 0;

//         for(int  i = 0 ; i < nums.size() ;i++){
//             sum += nums[i];

//             if(sum > maxI) maxI = sum;

//             if(sum < 0) sum = 0;

//         }
//         if(maxI < 0) return 0; - this line if u want max to be 0 or else remove line if negative max sums are allowed
//         return maxI;
//     }
// };



// follow up = print max subarray code below

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxI = INT_MIN , sum = 0;
//         int start = 0;
//         int ansStart = -1 , int ansEnd = -1;
//         for(int  i = 0 ; i < nums.size() ;i++){
//             if(sum == 0) start = i;
//             sum += nums[i];

//             if(sum > maxI) {
//                  maxI = sum;
//                  ansStart = start;  
//                  ansEnd = i; 
//              }
//             if(sum < 0) sum = 0;

//         }
//         if(maxI < 0) return 0; - this line if u want max to be 0 or else remove line if negative max sums are allowed
//         return maxI;
//     }
// };
