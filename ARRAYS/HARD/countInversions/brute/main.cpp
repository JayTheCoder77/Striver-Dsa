int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ;j++){
            if(a[i] > a[j]){
                count++;
            }
        }
    }
    return count;
}

tc = o(n2)
sc = o(1)