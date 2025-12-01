#include <bits/stdc++.h> 
// express in terms of index and target
// explore possibilities of that index

bool f(int i ,int k , vector<int> &arr , int n){
    if(k == 0) return true;
    if(i < 0) return false;
    if(i == 0) return (arr[0] == k);

    // take and not take
    bool notTake = f(i-1 , k , arr ,n);
    bool take = false;
    if(k >= arr[i]) take = f(i-1 , k-arr[i] , arr , n);

    return take | notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(n-1 , k , arr , n);
}

tc = o(2^n)
sc = o(n)