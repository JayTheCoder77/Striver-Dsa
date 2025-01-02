bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    // Write your code here.
    int n = A.size();
    int low = 0; 
    int high = n - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(A[mid] == key) return true;

        // duplicate case  low = mid = high cant determine which portion is sorted

        if(A[low] == A[mid] && A[mid] == A[high]){
            low = low + 1;
            high = high - 1;
        }

        // left sorted
        if(A[low] <= A[mid]){
            if(A[low] <= key && key <= A[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        // right sorted
        if (A[mid] <= A[high]) {
            if(A[mid] <= key && key <= A[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return false;
}
TC = O(logn) base2

test case = where many duplicates we will end up shrinking the array a lot so o(n/2)