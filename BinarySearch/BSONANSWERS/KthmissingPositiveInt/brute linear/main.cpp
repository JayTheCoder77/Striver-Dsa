int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    for(int i = 0 ; i < vec.size() ; i++){
        if(vec[i] <= k) k++;
        else break;
    }
    return k;
}
tc = o(n)