class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> dp (4 , 0);
        // dp = previous
        dp[0] = max(arr[0][1] , arr[0][2]);
        dp[1] = max(arr[0][0] , arr[0][2]);
        dp[2] = max(arr[0][1] , arr[0][0]);
        dp[3] = max(arr[0][0] , max(arr[0][2] , arr[0][1]));
        
        for(int day = 1 ; day < n ; day++){
            vector<int> temp(4,0);
            for(int last = 0 ; last < 4 ; last++){
                temp[last] = 0;
                for(int task = 0 ; task < 3 ; task++){
                    if (task != last) {
                        temp[last] = max(temp[last], arr[day][task] + dp[task]);
                    }
                }
            }
            dp = temp;
        }
        
        return dp[3];
    }
};

tc - o(n x 4 x 3)
sc - o(4)