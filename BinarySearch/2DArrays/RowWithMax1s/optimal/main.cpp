int lowerBound(vector<int> &arr, int n, int x){
    int low = 0; 
    int high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >= x){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    // Write Your Code Here
    // lower bound(1)
    // upper bound(0)
    // first occurence of (1)
    // all three are correct approaches


    // here is the code for lower bound(1)
    int numOfOnes = 0;
    int cnt_max = 0, rowIndex = -1;
    for(int i = 0 ; i < n ; i++){
        numOfOnes = m - lowerBound(matrix[i],m,1);
        if(numOfOnes > cnt_max){
            cnt_max = numOfOnes;
            rowIndex = i;
        }
    }
    return rowIndex;
}

tc = o(n x log2m) where m is size of individual row