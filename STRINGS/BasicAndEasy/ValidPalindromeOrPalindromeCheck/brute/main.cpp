class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for(char c : s){
            if(isalnum(c)) newStr += tolower(c);
        }
        int start = 0 , end = newStr.size()-1;
        while(start < end){
            if(newStr[start++] != newStr[end--]) return false;
        }
        return true;
    }
};

tc = o(n) => o(n) + o(m) where n is og string m is new string but in most cases m = n
sc = o(n)