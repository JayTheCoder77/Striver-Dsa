class Solution {
    public:
        int generate(vector<int>& nums, int k){
            int l = 0 , r = 0;
            int count = 0;
            int n = nums.size();
            map<int,int> mpp; // num ,frequency
            while(r < n){
                mpp[nums[r]]++;
                while(mpp.size() > k && l < n){
                    mpp[nums[l]]--;
                    if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                    l++;
                }
                count += r - l + 1;
                r++;
            }
            return count;
        }
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            int a =  generate(nums , k);
            int b = generate(nums , k-1); 
            return a - b;
        }
    };

    tc = o()