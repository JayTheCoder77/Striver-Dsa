top down

class Solution {
  public:
    int f(int ind , vector<int>& height ,vector<int> &dp , int k){
        if(ind == 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int minsteps = INT_MAX;

        for(int j = 1 ; j <= k ; j++){
            if(ind - j >= 0){
                int jump = f(ind - j , height , k) + abs(height[ind] - height[ind - j]);
                minsteps = min(minsteps , jump);
            }
        }
        
        return dp[ind] = minsteps;
    }
    int minCost(vector<int>& height , int k) {
        int n = height.size();
        vector<int> dp(n+1 , -1);
        return f(n-1 , height , dp , k);
    }
};

tc = o(n * k)
sc = o(n) + o(n)