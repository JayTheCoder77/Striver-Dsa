class Solution {
    public:
        // solved using recursion earlier
        // now using bit manipulation
        double myPow(double x, int n) {
            long long power = n;
            if(n < 0) power = -power;
            double ans = 1.0;
            while(power > 0){
            if(power % 2 == 1){
                ans = x * ans;
                power--;
            }
            power = power / 2;
            x = x * x;
            }
            return n < 0 ? 1.0 / ans : ans;
        }
    };