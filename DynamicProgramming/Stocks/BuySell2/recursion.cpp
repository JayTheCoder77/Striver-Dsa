class Solution {
public:
    int f(int i , int buy , vector<int>& prices){
        // base 
        // 1 - buy 
        // 0 - cannot buy
        int n = prices.size();
        if(i == n){
            return 0;
        }

        if(buy){
            // take / not take
            return max(-prices[i] + f(i + 1 , 0 , prices) , f(i + 1 , 1 , prices));    
        } 
        // deicde to sell / decide not to sell
        return max(prices[i] + f(i + 1 , 1 , prices) , f(i + 1 , 0 , prices));
    }
    int maxProfit(vector<int>& prices) {
        return f(0 , 1 , prices);
    }
};