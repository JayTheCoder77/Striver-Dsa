997. Find the Town Judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n + 1, 0);   // how many people trust this person
        vector<int> outDegree(n + 1, 0);  // how many people this person trusts

        for (auto &t : trust) {
            int a = t[0], b = t[1];
            outDegree[a]++;
            inDegree[b]++;   
        }
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i; 
            }
        }
        return -1;
    }
};