class Solution {
  public:
    int f(int ind , int wt , vector<int> &weight, vector<int> &value){
    
    	// if starting from n-1 write base case for 0 and vice versa
    	if(ind == 0){
    		if(weight[0] <= wt) return value[0];
    		else return 0;
    	}
    
    	int notTake = 0 + f(ind - 1 , wt , weight , value);
    	int take = INT_MIN;
    	if(weight[ind] <= wt) take = value[ind] + f(ind - 1 , wt - weight[ind] , weight , value);
    	return max(take , notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
	    return f(n-1 , W , wt , val);
    }
};

tc = o(2^n)
sc = o(n)