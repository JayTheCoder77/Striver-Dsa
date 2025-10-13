class Solution {
  public:
    int minCost(vector<int>& height , int k) {
        int n = height.size();
        vector<int> dp(n , 0);
        dp[0] = 0;
        for(int i = 1 ; i < n ; i++){
            int minsteps = INT_MAX;
            for(int j = 1 ; j <= k ; j++){
                if(i - j >= 0){
                    int jump = dp[i-j] + abs(height[i] - height[i - j]);
                    minsteps = min(minsteps , jump);
                }
            }
            dp[i] = minsteps;
        }
        return dp[n-1];
    }
};