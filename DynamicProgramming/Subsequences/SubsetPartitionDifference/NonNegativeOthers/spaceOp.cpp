int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totSum = 0;
        for(int i = 0 ; i < n ; i++) totSum += arr[i];
        int k = totSum;
        if(n == 0) return 0;
        vector<bool> prev(k+1 , false) , cur(k+1 , false);
        
        // base case
        prev[0] = true , cur[0] = true;
        prev[arr[0]] = true;
        
        // nested loops
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j <= k ; j++){
                // j = target loop
                bool notTake = prev[j];
                bool take = false;
                if(j >= arr[i]) take = prev[j-arr[i]];
                cur[j] = take || notTake;
            }
            prev = cur;
        }
        
        
         // dp[n-1][col -> 0....totalsum]
        int mini = 1e9;
        // optimization = no need to go until totsum as for example -> 
        // 3 + 7 = 7 + 3
        // so we avoid same calculations further by going only upto totsum / 2
        for(int s1 = 0 ; s1 <= totSum/2 ; s1++){
            // s2 = total - s1
            if(prev[s1]) mini = min(mini , (totSum - s1) - s1);
        }
        return mini;
}
