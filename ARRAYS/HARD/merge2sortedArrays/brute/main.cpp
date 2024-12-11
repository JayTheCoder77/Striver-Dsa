#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	vector <long long> ans;
	int left = 0 , right = 0;
	while(left < a.size() && right < b.size()){
		if(a[left] <= b[right]){
			ans.push_back(a[left]);
			left++;
		}
		else{
			ans.push_back(b[right]);
			right++;
		}
	}
	while(left < a.size()){
		ans.push_back(a[left]);
		left++;
	}
	while(right < b.size()){
		ans.push_back(b[right]);
		right++;
	}
	for(int i = 0 ; i < ans.size() ; i++){
		if(i < a.size()) a[i] = ans[i];
		else b[i - a.size()] = ans[i];
	}
}

TC =  O(n+m) +  O(n+m)
SC =  O(n+m)