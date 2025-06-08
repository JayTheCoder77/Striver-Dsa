for optimizing this further the internal loops can use disjoint set union 

#include<bits/stdc++.h>
bool comp(const vector<int> &a , const vector<int> &b){
    // sort according to profit
    return a[2] > b[2];
}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here 
    int n = jobs.size();
    sort(jobs.begin(), jobs.end() , comp);
    int totalProfit = 0 , cnt = 0 , maxDeadline = -1;
    for(int i = 0 ; i < n ; i++) maxDeadline = max(maxDeadline , jobs[i][1]);
    vector<int> hash (maxDeadline + 1 , -1);
    for(int i = 0 ; i < n ; i++){
        for(int j = jobs[i][1] ; j >= 1 ; j--){
            if(hash[j] == -1){
                cnt++;
                hash[j] = jobs[i][0];
                totalProfit += jobs[i][2];
                break;
            }
        }
    }
    return {cnt , totalProfit};
}


tc = o(nlogn + n * maxDeadline)
sc = o(maxDeadline)