class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2 , 0) , cur(2 , 0);

        ahead[0] = ahead[1] = 0;

        for(int i = n - 1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit = 0;
                if(buy){
                    // take / not take
                    cur[buy] = max(-prices[i] + ahead[0] , ahead[1]);    
                } 
                // deicde to sell / decide not to sell
                else cur[buy] = max(prices[i] + ahead[1] , ahead[0]);
            }
            ahead = cur;
        }   
        return ahead[1];
    }
};