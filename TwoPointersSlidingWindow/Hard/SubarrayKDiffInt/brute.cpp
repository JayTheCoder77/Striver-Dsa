#include<bits/stdc++.h>
int kDistinctSubarrays(vector<int> &arr, int n, int k)
{
    // Write your code here
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        map<int,int> mpp;
        for(int j = i ; j < n ; j++){
            mpp[arr[j]]++;
            if(mpp.size() == k) count++;
            else if(mpp.size() > k) break;
        }
    }
    return count;
}