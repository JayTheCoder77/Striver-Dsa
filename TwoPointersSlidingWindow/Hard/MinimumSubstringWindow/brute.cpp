class Solution {
    public:
      // Function to find the smallest window in the string s1 consisting
      // of all the characters of string s2.
      string smallestWindow(string &s1, string &s2) {
          if (s2.length() > s1.length()) return "";
          
          int minLen = INT_MAX;
          int sIndex = -1;
          for(int i = 0 ; i < s1.length() ; i++){
              int hash[256] = {0};
              int count = 0;
              for(int j = 0 ; j < s2.length() ; j++) { hash[s2[j]]++; }
              for(int j = i ; j < s1.length() ; j++){
                  if(hash[s1[j]] > 0) count++;
                  hash[s1[j]]--;
                  if(count == s2.length()){
                      if(j - i + 1 < minLen){
                      minLen = j - i + 1;
                      sIndex = i;
                      break;
                      }
                  }
          }
          }
          return (sIndex == -1) ? "" : s1.substr(sIndex, minLen);
          
      }
  };

  tc = o(n2) 
  sc = o(256)