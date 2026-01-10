// s1 - s2 = D  where s1 >= s2
// but s1 = total - s2
// total - s2 - s2 = d
// s2 = ( total - d ) / 2
// boiled down to count subsets with this formula instead of s1 - s2 = d
// now just apply the concept of count subsets with sum = k


#include <bits/stdc++.h> 

int mod = (int)(1e9 + 7);

int f(int i , vector<int>& arr, int k){
	int n = arr.size();
	if (i == 0) {
        if (k == 0 && arr[0] == 0) return 2;
        if (k == 0) return 1;
        if (arr[0] == k) return 1;
        return 0;
    }
	// not pick
	int notPick = f(i - 1 , arr , k);
	// pick
	int pick = 0;
	if(arr[i] <= k) pick = f(i - 1 , arr , k - arr[i]);

	return (pick + notPick) % mod;
}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	return f(n-1 , arr , k);
}

int countPartitions(int n, int d, vector<int> &arr) {
	int totSum = 0;
    for(auto &it : arr) totSum += it;
    if((totSum - d) < 0 || ((totSum - d) % 2) != 0) return false;
    return findWays(arr , (totSum - d) / 2);
}