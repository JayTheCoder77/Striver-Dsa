class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int l = 0 , r = 0;
            int zeroes = 0 , maxLen = 0;
            while(r < nums.size()){
                if(nums[r] == 0) zeroes++;
                if(zeroes > k){
                    if(nums[l] == 0) zeroes--;
                    l++;
                }
                if(zeroes <= k){
                int len = r - l + 1;
                maxLen = max(maxLen , len);
                }
                r++;
            }
            return maxLen;
        }
    };

    tc = o(n)
    sc = o(1)