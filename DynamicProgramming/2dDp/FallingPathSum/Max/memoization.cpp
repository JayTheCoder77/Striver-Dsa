class Solution {
  public:
    int f(vector<vector<int>> &dp , vector<vector<int>> &matrix , int i , int j){
        int n = matrix.size() , m = matrix[0].size();
        if(j < 0 || j > m-1) return -1e8;
        if(i == 0) return matrix[0][j];
        if(dp[i][j] != -1) return dp[i][j];
    
        int s = matrix[i][j] + f(dp,matrix , i-1 , j);
        int ld = matrix[i][j] + f(dp,matrix , i-1 , j-1);
        int rd = matrix[i][j] + f(dp,matrix , i-1 , j+1);
    
        return dp[i][j] = max(s , max(ld , rd));
    }
    int maximumPath(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> dp(n , vector<int>  (m , -1));
        int maxi = -1e8;
        for(int j = 0 ; j < m ; j++){
            maxi = max(maxi ,  f(dp , matrix , n-1 , j));
        }
        return maxi;
    }
};

tc = o(n x m)
sc = o(n x m) + o(n)