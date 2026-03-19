class Solution {
public:
    bool f(int i  , int j , string p , string s){
        // only p contains the wild card ie ? and *
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0 && i >= 0){
            for(int k = 0 ; k <= i ; k++){
                if (p[k] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(p[i] == s[j] || p[i] == '?') return f(i-1 , j-1 , p , s);

        if(p[i] == '*'){
            return f(i-1 , j , p , s) || f(i , j-1 , p , s);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n = p.length() , m = s.length();
        return f(n-1 , m-1 , p , s);
    }
};

tc = exponential
sc = o(n + m)