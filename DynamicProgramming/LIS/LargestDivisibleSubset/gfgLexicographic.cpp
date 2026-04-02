class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        
        
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<vector<int>> dp(n);

        for(int i = 0; i < n; i++){
            dp[i] = {arr[i]};
        }

        vector<int> ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0){
                    vector<int> temp = dp[j];
                    temp.push_back(arr[i]);

                    if(temp.size() > dp[i].size()){
                        dp[i] = temp;
                    }
                    else if(temp.size() == dp[i].size() && temp > dp[i]){
                        dp[i] = temp;
                    }
                }
            }

            // update global answer
            if(dp[i].size() > ans.size()){
                ans = dp[i];
            }
            else if(dp[i].size() == ans.size() && dp[i] > ans){
                ans = dp[i];
            }
        }

        return ans;
    }
};

