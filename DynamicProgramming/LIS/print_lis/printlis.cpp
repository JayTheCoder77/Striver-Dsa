class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n + 1 , 1);
        vector<int> hash (n);
        for(int i = 0 ; i < n ; i++) hash[i] = i;
        int maxi = 1;
        int lastIndex = 0;
        for(int ind = 0 ; ind < n ; ind++){
            for(int prev = 0 ; prev < ind ; prev++){
                if(nums[prev] < nums[ind] && 1 + dp[prev] > dp[ind]){
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
            if(dp[ind] > maxi){
                maxi = dp[ind];
                lastIndex = ind;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        int ind = 1;
        while(hash[lastIndex] != lastIndex){
           lastIndex = hash[lastIndex];
           temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin() , temp.end());
        return temp;
    }
};