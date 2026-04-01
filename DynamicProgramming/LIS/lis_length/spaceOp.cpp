class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next (n + 1 , 0) , cur (n + 1 , 0);
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int prev_ind = ind-1 ; prev_ind >= -1 ; prev_ind--){
                int notTake = next[prev_ind + 1];
                int take = 0;
                if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
                    // take
                    take =  1 + next[ind + 1];
                }
                cur[prev_ind + 1] = max(take , notTake);
            }
            next = cur;
        }
        return cur[-1 + 1];
    }
};

tc = o(n^2)
sc = o(n) x 2