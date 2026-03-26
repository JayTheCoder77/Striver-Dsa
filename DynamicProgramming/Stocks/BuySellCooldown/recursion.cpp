class Solution {
public:
    int f(int i , int buy , vector<int>& prices){
        int n = prices.size();
        if(i >= n){
            return 0;
        }
        if(buy == 1){
            return max(-prices[i] + f(i + 1 , 0 , prices) , f(i + 1 , 1 , prices));    
        } 
        // i = n-1
        return max(prices[i] + f(i + 2 , 1 , prices) , f(i + 1 , 0 , prices));
    }
    int maxProfit(vector<int>& prices) {
        return f(0 , 1 , prices);
    }
};