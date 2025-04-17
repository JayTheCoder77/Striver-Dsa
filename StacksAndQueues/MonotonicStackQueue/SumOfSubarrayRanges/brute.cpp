#include<bits/stdc++.h>
int rangeSum(vector<int>&nums){
    // Write your code here.
    int sum = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        int largest = nums[i];
        int smallest = nums[i];
        for(int j = i ; j < nums.size() ; j++){
            largest = max(largest,nums[j]);
            smallest = min(smallest,nums[j]);
            sum += (largest - smallest);
        }
    }
    return sum;
}

tc = o(n2)
sc = o(1)