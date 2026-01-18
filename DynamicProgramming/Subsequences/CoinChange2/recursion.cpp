Row 1 - ways to reach each column using first coin
Row 2 - ways to reach each column using first and second coin
Row 3 - ways to reach each column using first, second and third coin
Row last - ways to reach each column using all coins


class Solution {
public:
    int f(int ind , int amount, vector<int>& coins){
        // base
        if(ind == 0){
            return (amount % coins[0] == 0) ? 1 : 0;
        }

        int notPick = f(ind - 1 , amount , coins);
        int pick = 0;
        if(coins[ind] <= amount) pick = f(ind , amount - coins[ind] , coins);
        
        return notPick + pick;
    }
    int change(int amount, vector<int>& coins) {
        return f(coins.size() - 1 , amount , coins);
    }
};

tc = exponential
sc = o(target)