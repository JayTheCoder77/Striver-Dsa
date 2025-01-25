int upperBound(vector<int> &arr, int x, int n){
	int low = 0;
	int high = n - 1;
	int ans = n;
	while (low <= high){
		int mid = (low + high) / 2;
		if(arr[mid] > x){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans;
}
int findSmallerElements(vector<vector<int>> &matrix,int current,int n,int m){
    int total = 0;
    for(int i = 0 ; i < n ; i++){
        total += upperBound(matrix[i],current,m);
    }
    return total;
}
int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    int low = INT_MAX;
    int high = INT_MIN;
    n = matrix.size();          // redefined n to be rows and m to be cols
    m = matrix[0].size();
    for(int i = 0 ; i < n ; i++){
        low = min(low,matrix[i][0]);
        high = max(high,matrix[i][m-1]);
    }
        int required = (m * n) / 2;
    while(low <= high){
        int mid = (low + high) / 2;
        int smallerEquals = findSmallerElements(matrix,mid,n,m);
        if(smallerEquals <= required)low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

tc = o(n) for finding max and min + o(log(10^9) * n * logm)
                                    main bs       find smaller * upper bound