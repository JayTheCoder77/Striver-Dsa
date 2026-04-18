class Solution {
public:
  int f(int i, vector<int> &arr, int k) {
    int n = arr.size();
    // base
    if (i == n)
      return 0;
    int len = 0, sum = 0, maxAns = 0;
    int maxi = INT_MIN;
    for (int j = i; j < min(n, i + k); j++) {
      len++;
      maxi = max(maxi, arr[j]);
      sum = (len * maxi) + f(j + 1, arr, k);
      maxAns = max(maxAns, sum);
    }

    return maxAns;
  }
  int maxSumAfterPartitioning(vector<int> &arr, int k) { 
    return f(0, arr, k); 
  }
};