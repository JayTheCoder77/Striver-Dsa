class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int size = cuts.size();
        vector<vector<int>> dp(size , vector<int> (size , 0));

        for(int i = size - 2 ; i >= 1 ; i--){    
            for(int j = i ; j <= size - 2 ; j++){
                int mini = INT_MAX;
                for(int ind = i ; ind <= j ; ind++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(mini , cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][size-2];
    }
};