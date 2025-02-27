class Solution {
    public:
        const long long MOD = 1000000007LL;
        
        long long pow(long long x, long long n) {
            long long result = 1;
            
            // Keep squaring x and multiplying to result when needed
            while (n > 0) {
                // If current bit in n is 1, multiply result by current x
                if (n % 2 == 1) {
                    result = (result * x) % MOD;
                }
                
                // Square x for next iteration
                x = (x * x) % MOD;
                
                // Shift to next bit
                n /= 2;
            }
            
            return result;
        }
        
        int countGoodNumbers(long long n) {
            long long even = (n+1)/2;
            long long odd = n/2;
            long long first = pow(5, even) % MOD;
            long long second = pow(4, odd) % MOD;
            return (int)((first * second) % MOD);
        }
    };

    tc = 0(logn)
    tc = 0(1)