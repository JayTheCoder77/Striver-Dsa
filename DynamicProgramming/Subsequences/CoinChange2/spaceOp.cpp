class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> prev (amount + 1 , 0) , cur (amount + 1 , 0);

        for(int i = 0 ; i <= amount ; i++){
            if(i % coins[0] == 0) prev[i] = 1;
        }

        for(int i = 1 ; i < coins.size() ; i++){    
            for(int j = 0 ; j <= amount ; j++){
                long long notPick = prev[j];
                long long pick = 0;
                if(coins[i] <= j) pick = cur[j - coins[i]];
                cur[j] = pick + notPick;
            }
            prev = cur;
        }

        return prev[amount];
    }
};