class Solution {
  private:
  vector<int> topoSort(int V, vector<vector<int>>& adjList) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adjList[i]) indegree[it]++;
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adjList[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }

  public:
    string findOrder(vector<string> &words) {
        // Step 1: find unique characters
        set<char> uniqueChar;
        for (auto &word : words) {
            for (auto c : word) {
                uniqueChar.insert(c);
            }
        }
        
        int k = uniqueChar.size();

        // Step 2: map chars to indices
        unordered_map<char, int> charToIndex;
        unordered_map<int, char> indexToChar;
        int idx = 0;
        for (auto c : uniqueChar) {
            charToIndex[c] = idx;
            indexToChar[idx] = c;
            idx++;
        }

        // Step 3: build adjacency list
        vector<vector<int>> adj(k);
        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());

            // ❌ Case 1: prefix violation
            if (s1.size() > s2.size() && s1.substr(0, len) == s2) {
                return "";
            }

            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[charToIndex[s1[ptr]]].push_back(charToIndex[s2[ptr]]);
                    break;
                }
            }
        }

        // Step 4: topological sort
        vector<int> topo = topoSort(k, adj);

        // ❌ Case 2: cycle detected
        if (topo.size() != k) return "";

        // Step 5: convert topo indices back to chars
        string ans;
        for (auto i : topo) {
            ans += indexToChar[i];
        }
        return ans;
    }
};