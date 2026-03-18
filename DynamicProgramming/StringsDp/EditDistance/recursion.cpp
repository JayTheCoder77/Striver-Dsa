class Solution {
public:
    int f(int i , int j , string word1, string word2){

        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(word1[i] == word2[j]){
            return f(i-1 , j-1 , word1 , word2);
        }
        // int insert = 1 + f(i , j-1 , word1 , word2);
        // int del = 1 + f(i-1 , j , word1 , word2);
        // int replace = 1 + f(i-1 , j-1 , word1 , word2);

        return 1 + min(f(i , j-1 , word1 , word2) , min(f(i-1 , j , word1 , word2) , f(i-1 , j-1 , word1 , word2)));

    }
    int minDistance(string word1, string word2) {
        int n = word1.length() , m = word2.length();
        return f(n-1 , m-1 , word1 , word2);
    }
};