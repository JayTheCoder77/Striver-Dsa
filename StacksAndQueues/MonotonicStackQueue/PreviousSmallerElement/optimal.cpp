// smallest element to left
#include <bits/stdc++.h>
vector<int> previousSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    vector<int> nse(n , -1);
    for(int i = 0 ; i < n; i++){
        while(!s.empty() && arr[i] <= s.top()){
            s.pop();
        }
        nse[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return nse;
}

tc = o(2n) push in stack + push in vector
sc = o(n) + o(n)