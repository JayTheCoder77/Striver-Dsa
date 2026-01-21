#include<bits/stdc++.h>
int f(int ind , int wt , vector<int> &profit, vector<int> &weight){
    int n = weight.size();

    // base
    if(ind == 0){
        return (wt / weight[0]) * profit[0];
    }

    int notTake = f(ind - 1, wt , profit , weight);
    int take = -1e9;
    if(weight[ind] <= wt) take = profit[ind] + f(ind , wt - weight[ind] , profit , weight);
    return max(take , notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    return f(n-1 , w , profit , weight);
}

tc = exponential
sc = o(w)