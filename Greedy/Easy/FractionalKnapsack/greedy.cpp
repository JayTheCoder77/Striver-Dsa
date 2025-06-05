#include <bits/stdc++.h> 

// this contains {weight , values}

 // per unit wt check
// (100 , 20) = 20 -> gives 100
// therefore 1 -> gives 100 / 20 = 5

bool compareByUnit(const pair<int,int> &a , const pair<int,int> &b){
    if(((double)a.second / a.first) > ((double)b.second / b.first)) return true;
    return false;
}
double maximumValue (vector<pair<int, int>>& arr, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(arr.begin() , arr.end() , compareByUnit);
    double totalVal = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i].first <= w){
            totalVal += arr[i].second;
            w -= arr[i].first;
        }
        else{
            totalVal += double(arr[i].second) / (arr[i].first) * w;
            break;
        }
    }
    return totalVal;
}