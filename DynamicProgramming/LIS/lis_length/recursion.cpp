class Solution {
public:
    int f(int ind , int prev_ind , vector<int>& nums){
        int n = nums.size();
        if(ind == n) return 0;
        // take or not take
        int notTake = f(ind + 1 , prev_ind , nums);
        int take = 0;
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            // take
            take =  1 + f(ind + 1 , ind , nums);
        }
        return max(take , notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        return f(0 , -1 , nums);
    }
};

tc = o(2^n)
sc = o(n)