class Solution {
    public:
        // pattern
        // 0th bit -> wont be set for element which appears once
        // 1st bit -> will be set for element which appears once
        // 2nd bit -> will be set for element which appears once
    
        // bit wont be set which has all the position bits as multiple of 6
        // eg the 2nd bit position of all the numbers
    
        int singleNumber(vector<int>& nums) {
            int ans = 0;
            for(int bit = 0 ; bit <= 31 ; bit++){
                int count = 0;
                for(int i = 0 ; i < nums.size() ; i++){
                    if(nums[i] & (1 << bit)) count++;
                }
                if(count % 3 == 1) ans = ans | (1 << bit);
            }   
            return ans;
        }
    };

    tc = 0(n * 32)
    sc = o(1)

better 2

    class Solution {
        public:
            // pattern
            // 0th bit -> wont be set for element which appears once
            // 1st bit -> will be set for element which appears once
            // 2nd bit -> will be set for element which appears once
        
            // bit wont be set which has all the position bits as multiple of 6
            // eg the 2nd bit position of all the numbers
        
            int singleNumber(vector<int>& nums) {
                sort(nums.begin(),nums.end());
                for(int i = 1; i < nums.size() ; i+=3){
                    if(nums[i-1] != nums[i+1]) return nums[i-1];
                }
                return nums[nums.size()-1];
            }
        };

        tc = o(nlogn) + o(n/3)
        sc = o(1)