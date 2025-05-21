#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    vector<pair<int,int>> freq;
    map<int , int> mpp;
    for(int i = 0 ; i < n ; i++) mpp[arr[i]]++;
    for (auto const& pair_val : mpp) {
        freq.push_back({pair_val.first, pair_val.second});
    }
    sort(freq.begin() , freq.end() , [](const pair<int, int>& a, const pair<int, int>& b){
        if (a.second != b.second) {
            return a.second > b.second; // Sort by frequency (descending)
        }
        return a.first > b.first;
});
    for (int i = 0; i < k && i < freq.size(); i++)
    {
        ans.push_back(freq[i].first); 
    }
    return ans;
}
tc = o(nlogn)
sc = o(n)