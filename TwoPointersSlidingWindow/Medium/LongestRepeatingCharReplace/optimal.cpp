class Solution {
    public:
        int characterReplacement(string& s, int k) {
            // code here
            int l = 0 , r = 0;
            int maxLen = 0;
            int hash[26] = {0};
            int maxF = 0;
            while(r < s.length()){
                hash[s[r] - 'A']++;
                maxF = max(maxF , hash[s[r] - 'A']);
                if((r - l + 1) - maxF > k){
                    hash[s[l] - 'A']--;
                    maxF = 0;
                    l++;
                }
                if((r - l + 1) - maxF <= k ) maxLen = max(maxLen , r - l + 1);
                r++;
            }
            return maxLen;
        }
    };

    tc = o(n)
    sc = o(26)