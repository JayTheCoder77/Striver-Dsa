class Solution {
    public:
        string minWindow(string s, string t) {
            if(t.length() > s.length()) return "";
            int l = 0 , r = 0;
            int minLen = INT_MAX;
            int hash[256] = {0}; 
            int count = 0;
            int sIndex = -1;
            for(int i = 0 ; i < t.length() ; i++) hash[t[i]]++;
            while(r < s.length()){
                if(hash[s[r]] > 0){
                    count++;
                }
                    hash[s[r]]--;
                    
                while(count == t.length()){
                    if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    sIndex = l;
                    }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    count--;
                }
                l++;
                }
                r++;
            }
            return sIndex == -1 ? "" : s.substr(sIndex , minLen);
        }
    };

    tc = o(t) + o(2s)
    sc = o(256)