#include <bits/stdc++.h> 
vector<int> getAllDivisors(int n){
    // Write your code here
    vector<int> divisors;
    for (int i = 1; i*i <= n; ++i) { // better than  i <= sqrt(n)
        if (n % i == 0) {
            divisors.push_back(i);   // Add the divisor i
            
            // Check if i is not equal to n/i to avoid duplication
            if (n / i != i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}