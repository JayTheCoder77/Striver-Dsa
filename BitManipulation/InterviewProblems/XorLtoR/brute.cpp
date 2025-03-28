int findXOR(int L, int R){
    // Write your code here.
    int xor1 = L;
    for(int i = L+1 ; i <= R ; i++){
        xor1 = xor1 ^ i;
    }
    return xor1;
}