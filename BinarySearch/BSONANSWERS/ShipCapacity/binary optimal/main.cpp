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
    int low = findmax(weights); // max
    int high = findsum(weights);  // sum
    int days = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        days = daysReq(weights,mid);
        if(days <= d) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

tc = o(n) to find max + o(n) to find sum + o(n * log2(sum-max+1))




leetcode sol:

class Solution {
public:
    int day(vector<int>&weights,int cap){
        int sum = 0 , days = 1;
        for(int i = 0 ; i < weights.size() ; i++){
            if(sum + weights[i] > cap){
                days += 1;
                sum = weights[i];
            }
            else{
                sum += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *std::max_element(weights.begin(),weights.end());
        int high = std::accumulate(weights.begin(), weights.end(), 0);
        int d = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            d = day(weights,mid);
            if(d <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};