vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    // s - sn = x - y
    // s2 - sn2 = x2 
    int n = a.size();
    long long sn = ((long long)n * (n + 1)) / 2;
    long long sn2 = ((long long)n * (n + 1) * (2LL*n + 1)) / 6;
    long long s = 0;
    long long s2 = 0;
    for(int i = 0 ; i < n ; i++){
        s += (long long)a[i];
        s2 += (long long)a[i] * (long long)a[i];
    }
    long long eq1 = s - sn;
    long long eq2 = s2 - sn2;
    eq2 = eq2 / eq1;
    long long x = (eq1 + eq2) / 2;
    long long y = x - eq1;

    return {(int)x , (int) y};
}

tc = o(n)
sc = o(1)