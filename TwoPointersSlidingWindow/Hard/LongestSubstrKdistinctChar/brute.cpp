#include <bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    map <char , int > mpp;
    int n = str.length();
    int maxLen  = 0;
    // Write your code here
    for(int i = 0 ; i < n ; i++){
        mpp.clear();
        for(int j = i ; j < n ; j++){
        mpp[str[j]]++;
        if(mpp.size() <= k) maxLen = max(maxLen , j - i + 1);
        else break;
    }   
    }
    return maxLen;
}


tc = o(n2) * o(log 256)
sc = o(256)