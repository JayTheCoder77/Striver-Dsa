int f(int ind , int len , vector<int> &price){

	// base
	if(ind == 0){
		return len * price[0];
	}

	int notTake = f(ind - 1, len , price);
	int take = INT_MIN;
	int rodLen = ind + 1;
	if(rodLen <= len) take = price[ind] + f(ind , len - rodLen , price);

	return max(take , notTake);
}
int cutRod(vector<int> &price, int n)
{
	return f(n-1 , n , price);
}


tc = exponential
sc = o(target)