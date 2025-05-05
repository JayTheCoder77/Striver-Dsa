class Solution {
    public:
      string minWindow(string& s1, string& s2) {
          // Write your Code here
          if (s2.length() > s1.length()) return "";
          int n = s1.length();
          int m = s2.length();
          string str;
          int i = 0, j = 0 , k = 0;
          int minLen = INT_MAX;
          // Forward pass
          while (j < n && k < m) {
              if (s1[j] == s2[k]) {
                  k++;
              }
              // Backward pass
              if(k == m){
                  i = j;
                  k = m - 1;
                  while(i >= 0 && k >= 0){
                  if (s1[i] == s2[k]) {
                  k--;
                  }
                  i--;
          }
          i++;
          if(minLen > j - i + 1){
              minLen = j - i + 1;
              str = s1.substr(i , j - i + 1);
          }
          k = 0 ;
          j = i + 1;
              }
              j++;
          }
          // all s2 characters not found in s1
          return str;
      }
  };
