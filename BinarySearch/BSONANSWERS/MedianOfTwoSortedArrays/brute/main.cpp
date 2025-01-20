double median(vector<int>& a, vector<int>& b) {
	// Write your code here. brute use mergesort
	vector<int> c;
	int n1 = a.size();
	int n2 = b.size();
	int i = 0;
	int j = 0;
	while(i < n1 && j < n2){
		if(a[i] < b[j]) c.push_back(a[i++]);
		else c.push_back(b[j++]);
	}
	while(i < n1) c.push_back(a[i++]);
	while(j < n2) c.push_back(b[j++]);
	int mid = (n1 + n2);
	if(mid%2 == 1) return c[mid/2];
	return (double)((double)(c[mid/2]) + (double)(c[mid/2-1])) / 2.0;
}

tc = o(n1 + n2)
sc = o(n1 + n2)