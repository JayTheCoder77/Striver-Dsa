bool f(int i , int k , vector<int> &arr , vector<vector<int>> &dp){
	// k = target
	int n = arr.size();
	if(k == 0) return true;
	if(i < 0) return false;
	if(i == 0) return (arr[i] == k);
	if(dp[i][k] != -1) return dp[i][k];

	bool notTake = f(i-1 , k , arr , dp);
	bool take = false;
	if(k >= arr[i]) take = f(i-1 , k - arr[i] , arr , dp);

	return dp[i][k] = take || notTake;
}
bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(int i = 0 ; i < n ; i++) sum += arr[i];
	if (sum % 2 != 0) return false;
	vector<vector<int>> dp(n , vector<int>((sum/2) + 1 , -1));
	return f(n-1 , sum/2 , arr , dp);
}