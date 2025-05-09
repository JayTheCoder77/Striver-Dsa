int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int n = arr.size();
	if(n == 1) return arr[0];
	if(arr[0] != arr[1]) return arr[0];
	if(arr[n-1] != arr[n-2]) return arr[n-1];
	int low = 1;
	int high = n - 2;
	while(low <= high){
		int mid = (low + high) / 2;
		if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
			return arr[mid];
		}

		// left half so trim left
		// if we are at odd check if earlier element is equal
		// if we are at even check if latter element is equal 
		if(((mid % 2) == 1 && arr[mid-1] == arr[mid]) || ((mid % 2) == 0 && arr[mid] == arr[mid + 1])){
			low = mid + 1;
		}
		// trim right as element is in left
		else{
			high = mid - 1;
		}
	}
	return -1;
}
tc = o(logn) base2