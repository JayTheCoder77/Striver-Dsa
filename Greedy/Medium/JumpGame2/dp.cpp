class Solution {
public:
    int generate(int ind, int jumps, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (ind >= n - 1) return jumps;

        if (dp[ind][jumps] != -1) return dp[ind][jumps];

        int mini = INT_MAX;
        for (int i = 1; i <= nums[ind]; i++) {
            if (ind + i < n) {
                mini = min(mini, generate(ind + i, jumps + 1, nums, n, dp));
            }
        }

        return dp[ind][jumps] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<vector<int>> dp(n, vector<int>(n, -1)); // Proper dynamic 2D array

        int ans = generate(0, 0, nums, n, dp);
        return (ans == INT_MAX) ? -1 : ans;
    }
};

tc = o(n2)
sc = o(n2)