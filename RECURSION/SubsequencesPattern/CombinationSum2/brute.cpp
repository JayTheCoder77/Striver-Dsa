#include <bits/stdc++.h>
void generateComb(set<vector<int>> &ans, vector<int> &ds, vector<int> &arr, int b, int ind) {
    if (b == 0) {
        ans.insert(ds);  // Store unique combinations
        return;
    }
    for (int i = ind; i < arr.size(); i++) {
        if (i > ind && arr[i] == arr[i - 1]) continue;  // Skip duplicates in the same recursion level
        if (arr[i] > b) break;  // No need to proceed further if arr[i] exceeds the remaining sum

        ds.push_back(arr[i]);
        generateComb(ans, ds, arr, b - arr[i], i + 1);  // Move to the next index
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target) {
    vector<int> ds;
    set<vector<int>> uniqueComb;
    sort(arr.begin(), arr.end());  // Sort to handle duplicates properly

    generateComb(uniqueComb, ds, arr, target, 0);

    return vector<vector<int>>(uniqueComb.begin(), uniqueComb.end());
}

tc = O(NlogN+ 2^N x K)
sc = O(2^N x K + N)
k is subset length