class Solution {
  public:
    int perfectSum(vector<int>& arr, int k) {
    	int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> prev(k + 1, 0), cur(k + 1, 0);

        // base case
        if (arr[0] == 0) {
            prev[0] = 2;
        } else {
            prev[0] = 1;
            if (arr[0] <= k)
                prev[arr[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            fill(cur.begin(), cur.end(), 0);

            for (int j = 0; j <= k; j++) {
                int notPick = prev[j];
                int pick = 0;
                if (arr[i] <= j)
                    pick = prev[j - arr[i]];

                cur[j] = (notPick + pick) % MOD;
            }
            prev = cur;
        }

        return prev[k];
    }
};