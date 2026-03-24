class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(5,0);
        vector<int> curr(5,0);
        for(int i=n-1;i>=0;i--){
            for(int j=3;j>=0;j--){
                if(j%2 == 0) curr[j] = max(-prices[i] + prev[j+1], prev[j]);
                else curr[j] = max(prices[i] + prev[j+1], prev[j]);
            }
            prev = curr;
        }
        return prev[0];
    }
};