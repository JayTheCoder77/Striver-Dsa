class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1 (n , 1);
        for(int ind = 0 ; ind < n ; ind++){
            for(int prev = 0 ; prev <= ind ; prev++){
                if(nums[prev] < nums[ind] && 1 + dp1[prev] > dp1[ind]){
                    dp1[ind] = 1 + dp1[prev];
                }
            }
        }
        
        
        vector<int> dp2 (n , 1);
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int prev = n-1 ; prev > ind ; prev--){
                if(nums[prev] < nums[ind] && 1 + dp2[prev] > dp2[ind]){
                    dp2[ind] = 1 + dp2[prev];
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; ++i)
        {
            if(dp1[i] != 1 and dp2[i] != 1)
            maxi = max ({maxi, dp1[i] + dp2[i] - 1});
        }
        return maxi;
    }
};