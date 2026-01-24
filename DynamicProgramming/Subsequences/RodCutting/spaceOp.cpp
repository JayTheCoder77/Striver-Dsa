class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> prev(n+1 , 0) , cur (n+1 , 0);
    	for(int i = 0 ; i <= n ; i++){
    		prev[i] = price[0] * i;
    	}
    
    	for(int i = 1 ; i < n ; i++){
    		for(int j = 0 ; j <= n ; j++){
    			int notTake = prev[j];
    			int take = INT_MIN;
    			int rodLen = i + 1;
    			if(rodLen <= j) take = price[i] + cur[j - rodLen];
    			cur[j] = max(take , notTake);
    		}
    		prev = cur;
    	}
    
    	return prev[n];
    }
};