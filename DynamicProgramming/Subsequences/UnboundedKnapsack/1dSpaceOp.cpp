class Solution {
  public:
    int knapSack(vector<int>& profit, vector<int>& weight, int w) {
        int n = weight.size();
        vector<int> prev(w + 1 , 0);
        
        for(int i = 0 ; i <= w ; i++){
            prev[i] = (i / weight[0]) * profit[0]; 
        }
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j <= w ; j++){
                int notTake = prev[j];
                int take = -1e9;
                if(weight[i] <= j) take = profit[i] + prev[j - weight[i]];
                prev[j] = max(take , notTake);
            }
        }
        return prev[w];
    }
};