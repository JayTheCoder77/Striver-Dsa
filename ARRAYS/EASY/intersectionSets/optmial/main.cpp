#include <bits/stdc++.h>
using namespace std;

vector<int> fintersection(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    int  i = 0;
    int  j = 0;
    vector<int> ans;
    while(i < n && j < m){
        if (a[i] < b[j])
        {
            i++;
        }
        else if(a[i] > b[j]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
        
    }
    return ans;
}

int main() {
    int n, m;

    // Input size of the two arrays
    cout << "Enter size of first array: ";
    cin >> n;
    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> a(n), b(m);

    // Input elements for first array
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Input elements for second array
    cout << "Enter elements of second array: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // Find union of both arrays
    vector<int> ans = fintersection(a, b);

    // Output the intersection
    cout << "intersection of the arrays: ";
    for (auto e : ans) {
        cout << e << " ";
    }

    return 0;
}
