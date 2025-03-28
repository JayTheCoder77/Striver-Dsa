#include <bits/stdc++.h> 
int occursOnce(vector<int> &a, int n){
	// Write your code here.
	map<int,int> mpp;
	for(int i = 0 ; i < n ; i++){
		mpp[a[i]]++;
	}
	for(auto it: mpp){
		if(it.second == 1) return it.first; 
	}
	return 0;
}
tc = o(nlogm) + o(m) m = map size (m can be n/2 + 1)
sc = o(m)

