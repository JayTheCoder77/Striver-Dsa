class Solution {
  public:
    int maximumPath(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<int> prev(m , 0);
        for(int j = 0 ; j < m ; j++) prev[j] = matrix[0][j];
        for(int i = 1 ; i < n ; i++){
            vector<int> cur(m , 0);
            for(int j = 0 ; j < m ; j++){
                int s = -1e8 , ld = -1e8 , rd = -1e8;
                s = matrix[i][j] + prev[j];
                if(j > 0) ld = matrix[i][j] + prev[j-1];
                if(j < m-1) rd = matrix[i][j] + prev[j+1];
                cur[j] = max(s , max(ld , rd));
            }
            prev = cur;
        }
        int maxi = prev[0];
        for(int j = 1 ; j < m ; j++) maxi = max(maxi , prev[j]);
        return maxi;
    }
};