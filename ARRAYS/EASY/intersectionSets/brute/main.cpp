#include <bits/stdc++.h>
using namespace std;

vector<int> fintersection(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    int vis[m] = {0};
    vector<int> ans;
    for (int i = 0; i < n;  i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(a[i] == b[j] && vis[j] == 0){
                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }
            if(b[j] > a[i]) break;
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
