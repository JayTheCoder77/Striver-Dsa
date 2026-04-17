class Solution {
public:
    bool isPalindrome(int i , int j , string s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i , string s){
        int n = s.length();
        if(i == n) return 0;
        int minCost = INT_MAX;
        
        for(int j = i ; j < n ; j++){
            if(isPalindrome(i , j ,s)){
                int cost = 1 + f(j+1 , s);
                minCost = min(minCost , cost);
            }
        }
        return minCost;
    }
    int minCut(string s) {
        return f(0 , s) - 1;
    }
};