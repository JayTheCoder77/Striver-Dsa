#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    vector<int> ans;
    for(int i = 0 ; i <= nums.size() - k ; i++){
        int maxi = nums[i];
        for(int j = i ; j <= i + k - 1; j++){
            maxi = max(maxi , nums[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}

tc = o(n - k) * k
sc = o(n - k)