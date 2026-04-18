class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
      int len = 0, sum = 0, maxAns = 0;
      int maxi = INT_MIN;
      for (int j = i; j < min(n, i + k); j++) {
        len++;
        maxi = max(maxi, arr[j]);
        sum = (len * maxi) + dp[j + 1];
        maxAns = max(maxAns, sum);
      }
      dp[i] = maxAns;
    }
    return dp[0];
  }
};