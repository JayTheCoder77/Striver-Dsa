#include <bits/stdc++.h>
using namespace std;

vector<int> funion(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;

    // Traverse both arrays
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            if (unionArr.size() == 0 || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        } else {
            if (unionArr.size() == 0 || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    // Process remaining elements of a[]
    while (i < n) {
        if (unionArr.size() == 0 || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    // Process remaining elements of b[]
    while (j < m) {
        if (unionArr.size() == 0 || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    return unionArr;
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
    vector<int> ans = funion(a, b);

    // Output the union
    cout << "Union of the arrays: ";
    for (auto e : ans) {
        cout << e << " ";
    }

    return 0;
}
