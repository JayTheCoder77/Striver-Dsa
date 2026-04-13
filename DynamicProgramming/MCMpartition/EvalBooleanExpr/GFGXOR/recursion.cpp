// User function Template for C++
class Solution {
  public:
    int f(int i , int j , bool isTrue , string &s){
        if(i > j) return 0;
        if(i == j){
            if(isTrue == 1) return s[i] == 'T';
            else return s[i] == 'F'; 
        }
        int ways = 0;
        for(int ind = i+1 ; ind <= j-1 ; ind = ind + 2){
            int lt = f(i , ind-1 , 1 , s);
            int lf = f(i , ind-1 , 0 , s);
            int rt = f(ind+1 , j , 1 , s);
            int rf = f(ind+1 , j , 0 , s);
            
            if(s[ind] == '&'){
                if(isTrue) ways += lt * rt;
                else ways += (lt * rf) + (lf * rt) + (rf * lf);
            }
            else if(s[ind] == '|'){
                if(isTrue) ways += (lt * rt) + (lt * rf) + (lf * rt);
                else ways += (lf * rf);
            }
            else{
                // ^ xor
                if(isTrue) ways += (lt * rf) + (lf * rt);
                else ways += (lt * rt) + (lf * rf);
            }
        }
        return ways;
    }
    int countWays(string &s) {
        return f(0 , s.length() - 1 , 1 , s);
    }
};