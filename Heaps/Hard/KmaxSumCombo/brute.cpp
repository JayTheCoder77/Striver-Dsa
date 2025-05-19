#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	vector<int> sums;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
		sums.push_back(a[i] + b[j]);
	}
	}
	sort(sums.begin(), sums.end(), greater<int>());

    // Get top k
    vector<int> ans(sums.begin(), sums.begin() + k);
    return ans;
}

tc = o(n2 logn)
sc = o(n2)