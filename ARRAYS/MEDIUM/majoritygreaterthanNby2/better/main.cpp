// #include <bits/stdc++.h>
// int majorityElement(vector<int> v) {

// 	// hashing - better approach
// 	int n = v.size();
// 	int majorFactor = n/2;

// 	map<int,int> hash;

// 	for(int i = 0 ; i < n ; i++){
// 		hash[v[i]]++;
// 	}
// 	for(auto it : hash){
// 		if(it.second > majorFactor) return it.first;
// 	}
// 	return -1;
// }


// tc - o(n log n) + o (n)

// sc - o(n)