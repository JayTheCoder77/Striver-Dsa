class Solution {
  public:
    // Disjoint Set Find with Path Compression
    int findParent(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs(n);
        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            jobs[i] = make_pair(profit[i], deadline[i]);
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        // Sort by profit in descending order
        sort(jobs.rbegin(), jobs.rend());

        vector<int> parent(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++) parent[i] = i;

        int count = 0, totalProfit = 0;

        for (auto &job : jobs) {
            int p = job.first;
            int d = job.second;
            int availableDay = findParent(d, parent);

            if (availableDay > 0) {
                count++;
                totalProfit += p;
                parent[availableDay] = findParent(availableDay - 1, parent);
            }
        }

        return {count, totalProfit};
    }
};