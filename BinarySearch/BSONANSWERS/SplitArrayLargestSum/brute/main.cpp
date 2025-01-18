#include <bits/stdc++.h>
int split(vector<int> &a,int sum, int k){
    int splitCurrent = 1;
    int currentSum = 0;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] + currentSum > sum){
            splitCurrent += 1;
            currentSum = a[i];
        }
        else{
            currentSum += a[i];
        }
    }
    return splitCurrent;
}
int findmax(vector<int> &a){
    int maxi = INT_MIN;
    for(int i = 0 ; i < a.size() ; i++){
        maxi = max(maxi,a[i]);
    }
    return maxi;
}
int findsum(vector<int> &a){
    int sum = 0;
    for(int i = 0 ; i < a.size() ; i++){
        sum += a[i];
    }
    return sum;
}
int largestSubarraySumMinimized(vector<int> a, int k) {
    // Write Your Code Here
    int max = findmax(a); // low
    int sum = findsum(a); // high
    int splitNum = 0;
    for (int i = max; i <= sum; i++){
        splitNum = split(a,i,k);
        if(splitNum <= k) return i;
    }
    return -1;
}

tc = o(n) sum + o(n) max + o(n * (sum - max + 1))

// finding min(max) same as allocate books,painters partition