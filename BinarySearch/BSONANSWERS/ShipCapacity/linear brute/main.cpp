#include <bits/stdc++.h>
int findmax(vector<int>&weights){
    int maxi = INT_MIN;
    for(int i = 0 ; i < weights.size() ; i++){
        maxi = max(maxi,weights[i]);
    }
    return maxi;
}
int findsum(vector<int>&weights){
    int sum = 0;
    for(int i = 0 ; i < weights.size() ; i++){
        sum += weights[i];
    }
    return sum;
}
int daysReq(vector<int>&weights,int cap){
    int day = 1 , load = 0;
    for(int i = 0 ; i < weights.size() ; i++){
        if(load + weights[i] > cap){
            day += 1;
            load = weights[i]; 
        }
        else{
            load += weights[i];
        }
    }
    return day;
}
int leastWeightCapacity(vector<int> &weights, int d) {
    // Write your code here.
    int max = findmax(weights);
    int sum = findsum(weights);
    int days = 0;
    for(int i = max; i <= sum; i++){
        days = daysReq(weights,i);
        if(days <= d) return i;
    }
    return -1;
}

tc = o(n) for max + o(n) for sum + o(n * (sum - max+1))