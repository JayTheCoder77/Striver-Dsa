class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length() , m = s.length();
        vector<bool> prev (m+1 , 0) , cur (m+1 , 0);

        prev[0] = true;

        for(int j = 1 ; j <=m ; j++) prev[j] = false;

        for(int i = 1 ; i <= n ; i++){
            // cur is the current row's column
            // that cur's 0th row has to be assigned everytime

             bool fl = true;
            for(int k = 1 ; k <= i ; k++){
                if (p[k-1] != '*'){
                    fl = false;
                    break;
                }
            }
            // for every roow we assign the 0th col value
            cur[0] = fl;

            // below is the inner loop
            for(int j = 1 ; j <= m ; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?')  cur[j] = prev[j-1];

                else if(p[i-1] == '*'){
                    cur[j] = prev[j] || cur[j-1];
                }
                else cur[j] = false;
            }
            prev = cur;
        }
        return prev[m];
    }
};