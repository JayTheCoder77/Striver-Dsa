#include<bits/stdc++.h>
int f(int ind , int wt , vector<int> &profit, vector<int> &weight , vector<vector<int>> &dp){
    int n = weight.size();

    // base
    if(ind == 0){
        return (wt / weight[0]) * profit[0];
    }
    if (dp[ind][wt] != -1) return dp[ind][wt];
    int notTake = f(ind - 1, wt , profit , weight , dp);
    int take = -1e9;
    if(weight[ind] <= wt) take = profit[ind] + f(ind , wt - weight[ind] , profit , weight , dp);
    return dp[ind][wt] = max(take , notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n , vector<int> (w + 1 , -1));
    return f(n-1 , w , profit , weight , dp);
}

tc = o(n * wt)
sc = o(n * wt) + o(n)