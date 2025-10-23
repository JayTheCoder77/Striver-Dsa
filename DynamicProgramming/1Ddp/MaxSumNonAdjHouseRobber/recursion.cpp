class Solution {
public:
    int f(int ind , vector<int>& nums){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        int pick = nums[ind] + f(ind - 2 , nums);
        int notPick = 0 + f(ind - 1 , nums);

        return max(pick , notPick);
    }
    int rob(vector<int>& nums) {
        return f(nums.size() - 1, nums);
    }
};

tc = o(n2)