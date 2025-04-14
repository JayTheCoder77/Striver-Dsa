// smallest element to right
#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    vector<int> nse(n , -1);
    for(int i = n-1 ; i >= 0; i--){
        while(!s.empty() && arr[i] <= s.top()){
            s.pop();
        }
        nse[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return nse;
}

tc = o(2n)
sc = o(n) + o(n)