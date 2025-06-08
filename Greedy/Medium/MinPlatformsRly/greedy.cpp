int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at , at+n);
    sort(dt , dt+n);
    int i = 0 , j = 0;
    int maxc = 0;
    int count = 0;
    while(i < n){
        if(at[i] < dt[j]){
            count++;
            i++;
        }
        else if(dt[j] < at[i]){
            count--;
            j++;
        }
        maxc = max(maxc , count);
    }
    return maxc;
}
tc = o(2nlogn + 2n)
sc = o(1)