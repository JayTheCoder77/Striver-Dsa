most optimal in case of subarray sum k was using hashing 
as this is binary sum we can optimize it further
for more refer  D:\Striver-Dsa\ARRAYS\MEDIUM\subArraySumK

class Solution {
    public:
        int numSubarrayLessOrEqualSum(vector<int>& nums, int goal) {
            if(goal < 0) return 0;
            int l = 0 , r = 0;
            int count = 0 , sum = 0;
            while(r < nums.size()){
                sum += nums[r];
                while(sum > goal){
                    sum -= nums[l];
                    l++;
                }
                count += (r - l + 1);
                r++;
            }
            return count;  
        }
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            int count = numSubarrayLessOrEqualSum(nums,goal);
            int countMinusOne = numSubarrayLessOrEqualSum(nums,goal-1);
            return count - countMinusOne;
        }
    };

    tc = o(2 * 2n)
    sc = o(1)