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
              while((r - l + 1) - maxF > k){
                  hash[s[l] - 'A']--;
                  maxF = 0;
                  for(int i = 0 ; i < 26 ; i++) maxF = max(maxF , hash[i]);
                  l++;
              }
              if((r - l + 1) - maxF <= k ) maxLen = max(maxLen , r - l + 1);
              r++;
          }
          return maxLen;
      }
  };

  tc = o(2n * 26)
  sc = o(26)