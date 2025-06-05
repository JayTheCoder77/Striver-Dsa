dp is optimal 

this is greedy

class Solution {
  public:
    vector<int> minPartition(int amount) {
        // code here
        int coins [] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> result;
        for(int i = 9 ; i >= 0 ; i--){
            while(amount >= coins[i]){
                amount -= coins[i];
                result.push_back(coins[i]);
            }
        }
        return result;
    }
};