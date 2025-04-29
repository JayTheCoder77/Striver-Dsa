int longestRepeatingSubstring(string &str, int k) {
    // Write your code here.
    int maxLen = 0;
    for(int i = 0 ; i < str.size() ; i++){
        int hash[26] = {0};
        int maxF = 0;
        for(int j = i ; j < str.size() ; j++){
           hash[str[j] - 'A']++;
           maxF = max(maxF , hash[str[j] - 'A']);
           int changes = j - i + 1 - maxF;
           if(changes <= k) maxLen = max(maxLen , j - i + 1);
           else break;
        }
    }
    return maxLen;
}

tc = o(n2)
sc = o(26)