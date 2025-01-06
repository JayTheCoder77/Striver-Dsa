#include <bits/stdc++.h>
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	auto lb = std::lower_bound(arr.begin(),arr.end(),x) - arr.begin();
	return lb;
}

tc = O(LOG(BASE2)N)