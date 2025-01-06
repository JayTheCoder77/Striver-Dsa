int findPeakElement(vector<int> &arr) {
    // Write your code here
    int n = arr.size();
    if(n == 1) return 0;
    int low = 1;
    int high = n - 2;
    // edge cases of first and last element
    // first element
    if(arr[0] > arr[1]) return 0;
    // last element
    if(arr[n-1] > arr[high]) return (n-1);
    while(low <= high){
        int mid = (low + high) / 2;
        // peak can be on the left , right of mid  or mid itself
        if(arr[mid] > arr[mid + 1] && arr[mid - 1] < arr[mid]){
            return mid; 
        }
        // peak on right of mid
        else if(arr[mid-1] < arr[mid] && arr[mid] < arr[mid + 1]){
            low = mid + 1;
        }
        // peak on left of mid
        else{
            high = mid - 1;
        }
    }
    return -1;
}
tc = o(logn) base2