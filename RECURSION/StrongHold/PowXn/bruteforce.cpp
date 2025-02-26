double myPow(double x, int n) {
    // Write Your Code Here
    if(n < 0){
        long power = n * -1;
        double ans = 1;
        for(int i = 1 ; i <= power ; i++){
            ans *= x;
        }
    return 1/ans;
    }
    double ans = 1;
    for(int i = 1 ; i <= n ; i++){
        ans *= x;
    }
    return ans;
}

tc = o(n)
sc = o(1)