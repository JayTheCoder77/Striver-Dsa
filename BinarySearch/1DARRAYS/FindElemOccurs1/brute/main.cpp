int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here brute
	int n = arr.size();
	for(int i = 0 ; i < n; i++){
		// arr with one elem
		if (n == 1) return arr[0];
		// first elem
		if(i == 0){
			if(arr[i] != arr[i + 1]) return arr[0];
		}
		// last elemm
		else if (i == n - 1){
			if(arr[i] != arr[i-1]) return arr[n-1];
		}
		// other elem
		else{
			if(arr[i] != arr[i+1] && arr[i] != arr[i-1]) return arr[i];
		}
	}
}
tc = o(n)