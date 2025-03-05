tc = o(2^n * k)
k = len of subsequence
sc = o(k * x) + o(space by recursion)

#include <bits/stdc++.h>
void generateComb(vector<int> &arr,vector<int> &ds,vector<vector<int>> &ans, int n, int target,int ind){	
	if(target == 0){
		ans.push_back(ds);
		return;
	}
	for(int i = ind ; i < n ; i++){
		if(i > ind && arr[i] == arr[i - 1]) continue;
		if(arr[i] > target) break;
		ds.push_back(arr[i]);
		generateComb(arr,ds,ans,n,target-arr[i],i+1);
		ds.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	vector<vector<int>> ans;
	vector<int> ds;
	sort(arr.begin(),arr.end());
	generateComb(arr,ds,ans,n,target,0);
	return ans;
}


