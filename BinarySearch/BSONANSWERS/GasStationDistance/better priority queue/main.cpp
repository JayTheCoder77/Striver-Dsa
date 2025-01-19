#include <bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	// priority queue for improving o(n) to o(logn) as it gives max in logn
	int n = arr.size();
	vector<int>howMany(n-1,0);
	priority_queue<pair<long double,int>> pq; 	// n - 1 or n check later
	for(int i = 0 ; i < n-1 ; i++){
          pq.push({arr[i + 1] - arr[i], i});
        }
        for(int gas = 1 ; gas <= k ; gas++){
			auto tp = pq.top(); pq.pop();
			int sectionInd = tp.second;
			howMany[sectionInd]++;
			long double inDiff = arr[sectionInd + 1] - arr[sectionInd];
			long double newSecLen = inDiff / (long double)(howMany[sectionInd] + 1);
			pq.push({newSecLen,sectionInd});
	}	
	return pq.top().first;
}

tc = o(k * logn) + o(nlogn)
sc = o(n-1)