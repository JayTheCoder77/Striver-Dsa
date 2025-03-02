# bit manip is also a way but this is recursion

#include <bits/stdc++.h>
void generate(int ind , int n ,vector<int>&v, vector<int> &res,vector<vector<int>> &ans){
    if(ind >= n){
        ans.push_back(res);
        return;
    }
    res.push_back(v[ind]);
    generate(ind + 1, n ,v, res , ans);
    res.pop_back();
    generate(ind + 1, n ,v, res , ans);
} 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    int n = v.size();
    vector<int> res;
    vector<vector<int>> ans;
    generate(0, n, v, res, ans);
    return ans;
}
tc = o(2^n) * o(n)

sc = O(2ⁿ * n) (for storing subsets) + O(n) (for recursion)