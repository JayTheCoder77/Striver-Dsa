class Solution {
    public:
  
      // using the solution of binary subarray with sum
      // as we have to count odd nos. we just use 1 in place of odd nums
      int numSubarrayLessOrEqualSum(vector<int>& nums, int goal) {
              if(goal < 0) return 0;
              int l = 0 , r = 0;
              int count = 0 , sum = 0;
              while(r < nums.size()){
                  sum += (nums[r] % 2);  // as modulo 2 gives 1 for odd nums
                  while(sum > goal){
                      sum -= (nums[l] % 2); // as modulo 2 gives 1 for odd nums
                      l++;
                  }
                  count += (r - l + 1);
                  r++;
              }
              return count;  
          }
  
      
      int countSubarray(int n, vector<int>& nums, int k) {
          // Code here
          int count = numSubarrayLessOrEqualSum(nums,k);
          int countMinusOne = numSubarrayLessOrEqualSum(nums,k-1);
          return count - countMinusOne;
      }
  };