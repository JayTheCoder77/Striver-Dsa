#include <bits/stdc++.h>
using namespace std;
int main(){
    cout << "--------------------" << endl;
    int n;
    cin >> n;
    cout << "--------------------" << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "--------------------" << endl;

    map<int , int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    cout << "--------------------" << endl;

    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }
    



    cout << "--------------------" << endl;
    int q;
    cin >> q;
    while(q--){
        int c;
        cin >> c;
        cout << mpp[c] << endl;
    }
return 0;
}