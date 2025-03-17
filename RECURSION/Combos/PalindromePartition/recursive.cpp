#include <bits/stdc++.h> 
bool isPal(string s , int start , int end){
    while(start <= end){
        if(s[start++] != s[end--]) return false;
    }
    return true;
}
void generate(int i ,string &s, vector<string> &str ,  vector<vector<string>> &ans){
    if(i == s.size()){
        ans.push_back(str);
        return;
    }
    for(int j = i ; j < s.size() ; j++){
        if(isPal(s,i,j)){
            str.push_back(s.substr(i,j-i + 1));
            generate(j + 1,s , str , ans);
            str.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> str;
    generate(0,s,str,ans);
    return ans;
}

tc = o(n * 2^n)
tc = o(n * 2^n) includes recursive space
