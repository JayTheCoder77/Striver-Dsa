#include<vector>
#include <bits/stdc++.h>
int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
	int n = arr.size();
	int maxproduct = INT_MIN;
	for(int i = 0 ; i < n ; i++){
			int product = 1;						// for brute o(n3) with one more inner loop
		for(int j = i ; j < n ; j++){
			product *= arr[j];
			maxproduct = max(product,maxproduct);
		}
	}
	return maxproduct;
}

tc = o(n2)
sc = o(1)