// pattern -> if n % 4 == 1 ans = 1
// if n % 4 == 2 ans = n+1
// if n % 4 == 3 ans = 0
// if n % 4 == 0 ans = n
int pattern(int n){

    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n + 1;
    if(n % 4 == 3) return 0;
    if(n % 4 == 0) return n;

}
int findXOR(int L, int R){
    // Write your code here.
    return pattern(L-1) ^ pattern(R);
}

tc = o(1)
sc = o(1)