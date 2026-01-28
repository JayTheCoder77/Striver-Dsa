class Solution {
public:
    int f(int i , int j , string &text1, string &text2){
        if(i < 0 || j < 0) return 0;

        if(text1[i] == text2[j]){
            return 1 + f(i - 1 , j - 1 , text1 , text2);
        }

        return max(f(i-1 , j ,text1 , text2) , f(i , j-1 ,text1 , text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length() , m = text2.length();
        return f(n-1 , m-1 , text1 , text2);
    }
};

tc = o(2^n x 2^m) exponential
