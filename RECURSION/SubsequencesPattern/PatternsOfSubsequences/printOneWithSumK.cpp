#include <bits/stdc++.h> 
bool takeOrNot(int sum,int ind ,int n,int k,vector<int> &arr){
    if(ind == n){
        if(sum == k) return true;
        else return false;
    }
    if(takeOrNot(sum + arr[ind],ind+1,n,k,arr)) return true;
    if(takeOrNot(sum,ind+1,n,k,arr)) return true;
    return false;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return takeOrNot(0,0,n,k,arr);
}
tc = o(2^n)
sc = o(n)