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
    int low = findmax(a); // max
    int high = findsum(a); // sum
    int splitNum = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        splitNum = split(a,mid,k);
        if(splitNum > k) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

tc = o(n) sum + o(n) max + o(n * log2(sum-max+1))

// finding min(max) same as allocate books,painters partition