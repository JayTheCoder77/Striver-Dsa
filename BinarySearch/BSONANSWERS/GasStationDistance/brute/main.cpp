double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	int n = arr.size();
	vector<int>howMany(n-1,0);
	for(int gas = 1 ; gas <= k ; gas++){
		long double maxVal = -1;
		long double maxSection = -1;
		int maxInd = -1;
		for(int i = 0 ; i < n-1 ; i++){
			long double diff = arr[i + 1] - arr[i];
			long double sectionLength = diff/(long double)(howMany[i]+1);
			if(sectionLength > maxSection){
				maxSection = sectionLength;
				maxInd = i;
			}
		}
		howMany[maxInd]++;
	}	
	long double maxAns = -1;
        for (int i = 0; i < n - 1; i++) {
                long double diff = arr[i + 1] - arr[i];
                long double sectionLength =
                    diff / (long double)(howMany[i] + 1);
                maxAns = max(maxAns, sectionLength);
        }
	return maxAns;
}
tc = o(k * n) + o(n)
sc = o(n)