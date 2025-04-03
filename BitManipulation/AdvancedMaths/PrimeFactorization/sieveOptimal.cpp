class Solution {
    public:
        int spf[100000+1];
        void sieve() {
            for(int i = 1; i <= 100000; i++) spf[i] = i;
            for(int i = 2; i * i <= 100000; i++){
                if(spf[i] == i){
                    for(int j = i*i; j <= 100000; j += i){
                        if(spf[j] == j) spf[j] = i;
                    }
                }
            }
        }
        
        vector<int> findPrimeFactors(int N) {
            sieve();
            vector<int> ans;
            
            // Special handling for numbers larger than array size
            if(N > 100000) {
                // Try dividing by small primes first
                for(int i = 2; i <= 100000 && i*i <= N; i++) {
                    if(N % i == 0) {
                        while(N % i == 0) {
                            ans.push_back(i);
                            N /= i;
                        }
                    }
                }
                // If remaining N is > 1, it must be prime
                if(N > 1) ans.push_back(N);
                return ans;
            }
            
            // Normal case using precomputed spf
            while(N != 1) {
                ans.push_back(spf[N]);
                N = N / spf[N];
            }
            return ans;
        }
    };

    tc = o(nlog(logn)) + o(q * logn base2)
    sc = o(n)