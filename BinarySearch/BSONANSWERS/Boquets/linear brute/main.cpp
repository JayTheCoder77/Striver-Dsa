#include <bits/stdc++.h>
int findmax(vector <int> &arr,int n){
	int maxI = INT_MIN;
	for(int i = 0;i < n ; i++){
		maxI = max(maxI,arr[i]);
	}
	return maxI;
}
int findmin(vector <int> &arr,int n){
	int minI = INT_MAX;
	for(int i = 0;i < n ; i++){
		minI = min(minI,arr[i]);
	}
	return minI;
}
bool findBoq(vector <int> &arr,int boq ,int k, int m ,int n){
	int count = 0 , total = 0;
	for(int i = 0 ;i < n ;i++){
		if(arr[i] <= boq){
			count++;
		}
		else{
			total += count/k;
			count = 0;
		}
	}
	total += count/k;
	if(total >= m) return true;
	return false;
}
int roseGarden(vector<int> arr, int k, int m)
{
	// Write your code here
	int n = arr.size();
	int low = findmin(arr,n);
	int high = findmax(arr ,n);
	for(int i = low ; i <= high ; i++){
		if(findBoq(arr,i,k,m,n) == true){
			return i;
		}
	}
	return -1;
}

Tc = o( high - low + 1 ) X N