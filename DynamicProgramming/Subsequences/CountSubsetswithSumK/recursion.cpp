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

	return pick + notPick;
}
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	return f(n-1 , arr , k);
}


tc = o(2^n)
sc = o(n)