#include <bits/stdc++.h>
vector<int> nextGreaterElementII(vector<int>& a) {
    // Write your code here.
    stack<int> s;
    vector<int> nge(a.size() , -1);
    for(int i = 2 * a.size() - 1 ; i >= 0 ; i--){
        int ind = i % a.size();
        while(!s.empty() && s.top() <= a[ind]){
            s.pop();
        }
        if(i < a.size()){
            nge[i] = s.empty() ? -1 : s.top();
        }
        s.push(a[ind]);
    }
    return nge;
}

tc =o (4n) as we can insert 2n elements and also remove 2n elements we double the array hypotheically
sc = o(n) + o(n)