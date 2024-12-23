// optimal
// has two optimal approaches - one using kadane's algorithm and the other using observation but kadane is not intuitive so only discuss observation method in an interview 
// ignore kadane in interview for this problem

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxI = INT_MIN;
        int pre = 1 , suf = 1;
        for(int i = 0 ; i < n ; i++){
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;

            pre *= nums[i];
            suf *= nums[n-i-1];
            maxI = max(maxI , max(pre,suf));
        }
        return maxI;
    }
};

tc = o(n)
sc = o(1)