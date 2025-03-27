#include <bits/stdc++.h>
int divideTwoInteger(int dividend, int divisor) {
        // Special case for INT_MIN
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        
        if (dividend == divisor)
            return 1;
        
        // Determine sign
        bool sign = true;
        if ((dividend < 0 && divisor > 0) || (divisor < 0 && dividend > 0))
            sign = false;
        
        // Use long long to handle absolute values
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        
        long long ans = 0;
        while (n >= d) {
            long long temp = d, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            ans += multiple;
            n -= temp;
        }
        
        // Handle overflow cases
        if (ans > INT_MAX) {
            return sign ? INT_MAX : INT_MIN;
        }
        
        return sign ? ans : -ans;
    
} 
tc = o(logn base2) ^2
sc = o(1)