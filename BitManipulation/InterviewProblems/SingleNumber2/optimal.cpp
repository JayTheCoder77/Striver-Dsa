class Solution {
    public:
        // optimal sol - buckets 
        int singleNumber(vector<int>& nums) {
            int ones = 0;
            int twos = 0;
            // int threes = 0; we actually dont need this
            for(int i = 0 ; i < nums.size() ; i++){
                ones = (ones ^ nums[i]) & ~(twos);
                twos = (twos ^ nums[i]) & ~(ones);
            }
            return ones;
        }
    };

    tc = o(n)
    sc = o(1)