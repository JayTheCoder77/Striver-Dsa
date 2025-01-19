
int countOfGasSt(vector<int> &arr, long double dist){
	int n = arr.size();
	int cnt = 0;
	for(int i = 1 ; i < n ; i++){
		int numberinbetween = ((arr[i] - arr[i-1])/dist);
		if((arr[i] - arr[i-1])/dist == numberinbetween * dist){
			numberinbetween--;
		}
		cnt += numberinbetween;
	}
	return cnt;
}
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	// binary search will be diff as answer is in long double
	// ans range - [0,max dist]
	int n = arr.size();
	long double maxdist = 0;
	for(int i = 0 ; i < n-1 ; i++){
		long double diff = arr[i+1] - arr[i];
		maxdist = max(maxdist,diff);
	}
	long double low = 0;
	long double high = maxdist;
	long double difference = 1e-6;
	while(high - low > difference){
		long double mid = (low + high) / 2.0;
		int count = countOfGasSt(arr,mid);
		if(count > k)low = mid;
		else high = mid; 
	}
	return high;
}

tc = o(n * log2n) + o(n)