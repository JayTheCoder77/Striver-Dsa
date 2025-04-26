class Solution {
    public:
      int longestUniqueSubstr(string &s) {
          // code here
          int l = 0 , r = 0;
          int hash[256]; // char , index 
          for(int i = 0 ; i < 256 ; i++){
              hash[i] = -1;
          }
          int maxLen = 0;
          while(r < s.length()){
              // is in map
              if(hash[s[r]] != -1){
                  if(hash[s[r]] >= l) l = hash[s[r]] + 1;
              } 
              int len = r - l + 1;
              maxLen = max(maxLen , len);
              hash[s[r]] = r;
              r++;
          }
          return maxLen;
      }
  };

  tc = o(256) + o(n)
  sc = o(256)