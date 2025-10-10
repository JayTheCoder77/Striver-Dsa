class Solution {
  public:
    int f(int ind , vector<int>& height){
        if(ind == 0) return 0;
        
        int left = f(ind - 1 , height) + abs(height[ind] - height[ind - 1]);
        int right = INT_MAX;
        
        if(ind > 1) right = f(ind - 2 , height) + abs(height[ind] - height[ind - 2]);
        
        return min(left , right);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        return f(n-1 , height);
    }
};