#include <bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    // Write your code here
    int l = 0 , r = 0;
    int maxLen = 0;
    map <char , int> mpp;
    while(r < str.length()){
        mpp[str[r]]++;
        if(mpp.size() > k && l < str.length()){
            mpp[str[l]]--;
            if(mpp[str[l]] == 0) mpp.erase(str[l]);
            l++;
            }
        if(mpp.size() <= k) maxLen = max(maxLen , r - l + 1);
        r++;
        }
    return maxLen;
}


tc = o(n) * o(log 256)
sc = o(log 256)


// what if k is greater than the distinct characters in a string
// then better approach will be optimal
class Solution {
    public:
      int longestKSubstr(string &str, int k) {
  
     int l = 0 , r = 0;
      int maxLen = -1;
      map <char , int> mpp;
      while(r < str.length()){
          mpp[str[r]]++;
          while(mpp.size() > k && l < str.length()){
              mpp[str[l]]--;
              if(mpp[str[l]] == 0) mpp.erase(str[l]);
              l++;
              }
          if(mpp.size() == k) maxLen = max(maxLen , r - l + 1);
          r++;
          }
      return maxLen;
  }
  };
  