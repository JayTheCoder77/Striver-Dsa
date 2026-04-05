class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n , 1) , cnt (n , 1);
        int maxi = 1;
        for(int ind = 0 ; ind < n ; ind++){
            for(int prev = 0 ; prev < ind ; prev++){
                if(nums[prev] < nums[ind] && 1 + dp[prev] > dp[ind]){
                    // inherit
                    dp[ind] = 1 + dp[prev];    
                    cnt[ind] = cnt[prev]; 
                }
                else if(nums[prev] < nums[ind] && 1 + dp[prev] == dp[ind]) {
                    // inc count
                    cnt[ind] += cnt[prev]; 
                }
                maxi = max(maxi , dp[ind]);
            }
        }
        int nos = 0;
        for(int i = 0 ; i < n ; i++){
            if(dp[i] == maxi) nos += cnt[i];
        }
        return nos;
    }
};