class Solution {
public:
    int generate(int ind , int jumps ,vector<int>& nums , int n){
       if(ind >= n-1) return jumps;
       int mini = INT_MAX;
       for(int i = 1 ; i <= nums[ind] ; i++){
            mini = min (mini , generate(ind+i,jumps+1,nums,n));
       }
       return mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int ans = generate(0, 0, nums, n);
        return (ans == INT_MAX) ? -1 : ans;
    }
};

tc = o(n^n)
sc = o(n)