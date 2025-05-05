class Solution {
    public:
      string minWindow(string& s, string& t) {
          // Write your Code here
          if (t.length() > s.length()) return "";
          int minLen = INT_MAX , sIndex = -1;
          int i = 0 , j = 0;
          while(i < s.length() && j < t.length()){
              if(s[i] == t[j]) j++;
              i++;
          }
          if (j < t.length()) return "";

          int n = s.length() , m = t.length();
          for(int end = 0 ; end < n ; end++){
              if(s[end] == t[m-1]){
                  int subseqIndex = m - 2;
                  int windowEnd = end - 1;
                  while(subseqIndex >= 0 && windowEnd >= 0){
                      if (s[windowEnd] == t[subseqIndex]) {
                          subseqIndex--;
                      }
                      windowEnd--;
                  }
                  if(subseqIndex < 0){
                       int windowStart = windowEnd + 1;
                       int windowLength = end - windowStart + 1;
                  if(windowLength < minLen) {
                          minLen = windowLength;
                          sIndex = windowStart;
                  }
                  }
              }
          }

          return sIndex == - 1 ? "" : s.substr(sIndex , minLen);
      }
  };

  tc =
