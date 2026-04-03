class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        unordered_map<string, int> dp;

        // sort by length
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        int maxi = 1;

        for(string word : words){
            int best = 1;

            for(int i = 0; i < word.size(); i++){
                // remove ith character
                string prev = word.substr(0, i) + word.substr(i + 1);

                if(dp.find(prev) != dp.end()){
                    best = max(best, dp[prev] + 1);
                }
            }

            dp[word] = best;
            maxi = max(maxi, best);
        }

        return maxi;
    }
};