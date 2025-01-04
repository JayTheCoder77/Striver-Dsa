int findPeakElement(vector<int> &arr) {
    // Write your code here - brute linear
    int n = arr.size();
    for(int i = 0 ; i < n ; i++){
        if(((i == 0) || arr[i - 1] < arr[i]) && ((i == n-1) || arr[i] > arr[i+1])){
            return i;
        }
    }
}
tc = o(n)