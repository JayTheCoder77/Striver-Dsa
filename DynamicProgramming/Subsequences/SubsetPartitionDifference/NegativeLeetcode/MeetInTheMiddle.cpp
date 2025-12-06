class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());
        
        vector<vector<int>> leftSums(n + 1), rightSums(n + 1);
        
 // generate all subset sums for both halves
        for (int mask = 0; mask < (1 << n); ++mask) {
            int sumL = 0, cntL = 0;
            int sumR = 0, cntR = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sumL += left[i];
                    cntL++;
                }
                if (mask & (1 << i)) {
                    sumR += right[i];
                    cntR++;
                }
            }
            leftSums[cntL].push_back(sumL);
            rightSums[cntR].push_back(sumR);
        }
// sort right half for binary search
        for (int i = 0; i <= n; ++i)
            sort(rightSums[i].begin(), rightSums[i].end());
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int halfSum = totalSum / 2;
        int ans = INT_MAX;
        
 // try all subset sizes on left half
        for (int k = 0; k <= n; ++k) {
            for (int sumL : leftSums[k]) {
                int need = halfSum - sumL;
                auto &vec = rightSums[n - k];
                
                auto it = lower_bound(vec.begin(), vec.end(), need);
                
// check both close values
                if (it != vec.end())
                    ans = min(ans, abs(totalSum - 2 * (sumL + *it)));
                if (it != vec.begin()) {
                    --it;
                    ans = min(ans, abs(totalSum - 2 * (sumL + *it)));
                }
            }
        }
        return ans;
    }
};