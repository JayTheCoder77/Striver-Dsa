int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    // Arrivals and Departures in sorted order
    	vector<int> arrival(2401, 0);
    	vector<int> departure(2401, 0);
    	
    	for(int i=0; i<n; i++){
    	    arrival[at[i]]++;
    	    departure[dt[i]]++;
    	}
    	
    	int maxcount=0, count=0;
    	for(int i=0; i<2401; i++){
    	    count+=arrival[i];
    	    maxcount=max(maxcount, count);
    	    count-=departure[i];
    	}
    	return maxcount;
}

tc = o(n)
sc = o(2401) approx o(1)