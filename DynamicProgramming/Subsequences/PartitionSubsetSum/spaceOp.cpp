class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0 ; i < n ; i++) sum += nums[i];
        if(sum % 2 != 0) return false;
        int k = sum/2;
        vector<bool> prev(k+1 , false) , cur(k+1 , false);

        prev[0] = true , cur[0] = true;
        if(nums[0] <= k) prev[nums[0]] = true;

        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j <= k ; j++){
                // j = target loop
                bool notTake = prev[j];
                bool take = false;
                if(j >= nums[i]) take = prev[j-nums[i]];
                cur[j] = take || notTake;
            }
            prev = cur;
        }
        return prev[k];
    }
};