// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            int take = nums[i];
            if(i > 1) take += dp[i-2];
            int notTake = 0 + dp[i-1];
            dp[i] = max(take , notTake);
        }
        return dp[nums.size()-1];
    }
};

tc = o(n)
sc = o(n)