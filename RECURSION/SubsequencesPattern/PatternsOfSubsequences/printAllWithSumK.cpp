#include <bits/stdc++.h>
using namespace std;

void printAll(int ind, vector<int> &ds, int s, int sum, vector<int> &arr, int n) {
    if (ind == n) {
        if (s == sum) {
            for (auto it : ds) cout << it << " ";
            cout << endl;
        }
        return;
    }
    // Pick the element
    ds.push_back(arr[ind]);
    s += arr[ind];
    printAll(ind + 1, ds, s, sum, arr, n);
    
    // Not pick the element
    s -= arr[ind];
    ds.pop_back();
    printAll(ind + 1, ds, s, sum, arr, n);
}

int main() {
    vector<int> arr = {1, 2, 3}; // Use vector<int> instead of int array
    int n = arr.size();
    int sum = 2;
    vector<int> ds;
    printAll(0, ds, 0, sum, arr, n);
    return 0;
}

tc = o(2^n)
sc = o(n)