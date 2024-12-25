#include <bits/stdc++.h>
int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.
	auto lb = std::upper_bound(arr.begin(),arr.end(),x) - arr.begin();
	return lb;
}