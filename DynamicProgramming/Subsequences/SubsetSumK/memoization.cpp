#include <bits/stdc++.h> 
// express in terms of index and target
// explore possibilities of that index

bool f(int i ,int k , vector<int> &arr , int n , vector<vector<int>> &dp){
    if(k == 0) return true;
    if(i < 0) return false;
    if(i == 0) return (arr[0] == k);
    if(dp[i][k] != -1) return dp[i][k];
    // take and not take
    bool notTake = f(i-1 , k , arr ,n , dp);
    bool take = false;
    if(k >= arr[i]) take = f(i-1 , k-arr[i] , arr , n , dp);

    return dp[i][k] = take | notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n , vector<int>(k + 1 , -1));
    return f(n-1 , k , arr , n , dp);
}

tc = o(n x k)
sc = o(n x k) + o(n)