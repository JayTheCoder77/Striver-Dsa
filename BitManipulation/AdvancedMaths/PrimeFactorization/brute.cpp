void sieve(vector<bool>& sieve, int n) {
    sieve[0] = sieve[1] = false; // 0 and 1 are not primes
    for (int i = 2; i * i <= n; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
}

// Function to count the prime factors of a number
vector<int> countPrimes(int n) {
    vector<int> ans;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ans.push_back(i);
            while (n % i == 0) {
                n = n / i;
            }
        }
    }
    if (n != 1) {
        ans.push_back(n);
    }
    return ans;
}

// Function to find the prime factors of a given number N
vector<int> findPrimeFactors(int N) {
    vector<int> primeFactors;
    
    // Create a sieve to find all primes up to sqrt(N)
    int limit = sqrt(N) + 1;
    vector<bool> sieve(limit, true); // true means the number is prime
    sieve(sieve, N);

    // Try dividing N by each prime number less than or equal to sqrt(N)
    for (int i = 2; i <= sqrt(N); ++i) {
        if (sieve[i] && N % i == 0) {
            while (N % i == 0) {
                primeFactors.push_back(i);
                N /= i;
            }
        }
    }

    // If N is still greater than 1, then N itself is prime
    if (N > 1) {
        primeFactors.push_back(N);
    }

    return primeFactors;
}