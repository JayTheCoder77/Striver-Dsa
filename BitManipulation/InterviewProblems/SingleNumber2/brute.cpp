int elementThatAppearsOnce(vector<int> arr) {
	// Write your code here.
	map<int , int> mpp;
	for(int i = 0 ; i < arr.size() ; i++){
		mpp[arr[i]]++;
	}
	for(auto it : mpp){
		if(it.second == 1) return it.first;
	}
	return 0;
}

tc = o (nlogm) + o(m) 
sc = o (m) 

m = (n / 3) + 1 near about