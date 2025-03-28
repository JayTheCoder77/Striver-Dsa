1486. XOR Operation in an Array
class Solution {
    public:
        int xorOperation(int n, int start) {
            vector<int> nums (n,0);
            for(int i = 0 ; i < n ; i++){
                nums[i] = start + 2 * i; 
            }
            int xor1 = 0;
            for(int i = 0 ; i < nums.size() ; i++){
                xor1 = xor1 ^ nums[i];
            }
            return xor1;
        }
    };