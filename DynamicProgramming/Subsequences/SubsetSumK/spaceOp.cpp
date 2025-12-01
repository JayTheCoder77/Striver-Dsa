class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == 0) return k == 0;
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
        return prev[k];
    }
};

tc = o(n x k)
sc = o(k)