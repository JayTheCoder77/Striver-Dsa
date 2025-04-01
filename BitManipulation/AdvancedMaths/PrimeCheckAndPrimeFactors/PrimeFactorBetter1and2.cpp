#include <bits/stdc++.h>
bool prime(int n){
    if(n <= 1) return false; // 1 is not a prime number
    
    int count = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            count++;
            if(n/i != i){
                count++;
            }
        }
        if(count > 2) return false; // Non-prime if more than 2 divisors
    }
    return count == 2; // Prime if exactly 2 divisors
}
vector<int> countPrimes(int n)
{
    // Write your code here.
    vector<int> ans;
    for(int i = 1 ; i <= sqrt(n) ; i++){
        if(n % i == 0){
            if(prime(i)) ans.push_back(i);
            if(n/i != i){
                if(prime(n/i)) ans.push_back(n/i);
            }
        }
    }
    return ans;
}

tc = o(sqrt(n) * 2 * sqrt(n)) approx
sc = o(not predictable)




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



vector<int> countPrimes(int n)
{
    // Write your code here.
    vector<int> ans;
    for(int i = 2 ; i <= n ; i++){
        if(n % i == 0){
            ans.push_back(i);
            while(n % i == 0) n = n / i;
        }
    }
    return ans;
}

// eg = tc = o(13) for 780 
// tc for worst case = o(n)


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


