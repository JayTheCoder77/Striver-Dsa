class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // same concept as n meetings in a room
        // we arranged meetings according to end times
        // so we figure out max meetings and subtract from array size to get min    removals so basically
        // inverse of n meetings in a room
        int maxi = 1, n = intervals.size();
        if (n == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), comp);
        int lastEnd = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= lastEnd)
            {
                maxi++;
                lastEnd = intervals[i][1];
            }
        }
        return n - maxi;
    }
};
