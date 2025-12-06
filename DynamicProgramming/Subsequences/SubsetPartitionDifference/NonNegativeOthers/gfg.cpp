class Solution {

  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int totSum = 0;
        for (int i = 0; i < n; ++i) totSum += arr[i];

        // dp[s] = 1 if some subset has sum s
        vector<int> dp(totSum + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            int val = arr[i];
            // go backwards to avoid reusing the same element multiple times
            for (int s = totSum; s >= val; --s) {
                if (dp[s - val]) dp[s] = 1;
            }
        }

        int ans = INT_MAX;
        // only need to check up to totSum / 2
        for (int s1 = 0; s1 <= totSum / 2; ++s1) {
            if (dp[s1]) {
                int diff = totSum - 2 * s1;
                if (diff < ans) ans = diff;
            }
        }

        return ans;
    }
};