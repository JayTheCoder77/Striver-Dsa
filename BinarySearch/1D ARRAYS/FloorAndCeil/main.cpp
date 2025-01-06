pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int low = 0;
	int high = n - 1;	
	int c = -1;
	int f = -1;

	while(low <= high){
		int mid = (low + high) /2;
		if(a[mid] == x){
			f = x;
			c = x;
			return make_pair(f,c);
		}
		if(a[mid] <= x){
			f = a[mid];
			low = mid+1;
		}
		if(a[mid] >= x){
			c = a[mid];
			high = mid - 1;
		}
	}
		return make_pair(f,c);
}