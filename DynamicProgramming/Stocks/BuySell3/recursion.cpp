class Solution {
public:
    int f(int i , int buy , vector<int>& prices ,int cap){
        // base 
        // 1 - buy 
        // 0 - cannot buy
        int n = prices.size();
        if(cap == 0) return 0;
        if(i == n){
            return 0;
        }

        if(buy){
            // take / not take
            return max(-prices[i] + f(i + 1 , 0 , prices , cap) , f(i + 1 , 1 , prices , cap));    
        } 
        // deicde to sell / decide not to sell
        return max(prices[i] + f(i + 1 , 1 , prices , cap-1) , f(i + 1 , 0 , prices , cap));
    }
    int maxProfit(vector<int>& prices) {
        return f(0 , 1 , prices , 2);
    }
};

tc = exponential
sc = o(n)