bool f(int i , int k , vector<int> &arr){
	// k = target
	int n = arr.size();
	if(k == 0) return true;
	if(i < 0) return false;
	if(i == 0) return (arr[i] == k);

	bool notTake = f(i-1 , k , arr);
	bool take = false;
	if(k >= arr[i]) take = f(i-1 , k - arr[i] , arr);

	return take || notTake;
}
bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(int i = 0 ; i < n ; i++) sum += arr[i];
	if (sum % 2 != 0) return false;
	return f(n-1 , sum/2 , arr);
}
