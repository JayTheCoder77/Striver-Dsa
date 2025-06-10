#include <bits/stdc++.h>
vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    // Write your code here.
    vector<vector<int>> res;
    int i = 0;
    // left
    while (i < intervals.size() && intervals[i][1] < newInterval[0])
    {
        res.push_back(intervals[i]);
        i++;
    }
    // middle
    while (i < intervals.size() && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);
    // right
    while (i < intervals.size())
    {
        res.push_back(intervals[i]);
        i++;
    }
    return res;
}

tc = o(n)
sc = o(n)