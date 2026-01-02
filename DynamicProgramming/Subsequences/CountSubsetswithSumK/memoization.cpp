int f(int i, vector<int>& arr, int k, vector<vector<int>>& dp) {
    if (i == 0) {
        if (k == 0 && arr[0] == 0) return 2;
        if (k == 0) return 1;
        if (arr[0] == k) return 1;
        return 0;
    }

    if (dp[i][k] != -1) return dp[i][k];

    int notPick = f(i - 1, arr, k, dp);
    int pick = 0;
    if (arr[i] <= k)
        pick = f(i - 1, arr, k - arr[i], dp);

    return dp[i][k] = pick + notPick;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, arr, k, dp);
}



tc = o(n x sum)
sc = o(n x sum) + o(n)