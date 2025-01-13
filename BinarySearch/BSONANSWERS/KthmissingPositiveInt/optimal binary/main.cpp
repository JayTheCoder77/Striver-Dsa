int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    // typical binary search not possible here even bs on answers not possible here
    int low = 0;
    int high = n-1;
    // identify two nearby indexes
    while(low <= high){
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if(missing < k) low = mid + 1;
        else high = mid - 1;
    }
    return low + k;
    // else return high + 1 + k 
}

tc = o(logn)