class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0;
        for(int i = 0 ; i < n ; i++){
            if(i > maxIndex) return false;
            maxIndex = max(maxIndex , i + nums[i]);
        }
        return true;
    }
};

tc = o(n)
sc = o(1)

// int implementation
int minJumps(vector<int> &nums,int n) 
{
    // Write your code here.
        if (n <= 1) return 0;
        if (nums[0] == 0) return -1;

        int jumps = 1;         // at least one jump needed
        int farthest = nums[0];
        int currEnd = nums[0];

        for (int i = 1; i < n; i++) {
            if (i > farthest) return -1;

            farthest = max(farthest, i + nums[i]);

            if (i == currEnd && i != n - 1) {
                jumps++;
                currEnd = farthest;
            }
        }

        return jumps;
}