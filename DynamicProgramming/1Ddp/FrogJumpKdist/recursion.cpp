class Solution {
  public:
    int f(int ind , vector<int>& height , int k){
        if(ind == 0) return 0;
        
        int minsteps = INT_MAX;
        
        for(int j = 1 ; j <= k ; j++){
            if(ind - j >= 0){
                int jump = f(ind - j , height , k) + abs(height[ind] - height[ind - j]);
                minsteps = min(minsteps , jump);
            }
        } 
        
        return minsteps;
    }
    int minCost(vector<int>& height , int k) {
        int n = height.size();
        return f(n-1 , height , k);
    }
};