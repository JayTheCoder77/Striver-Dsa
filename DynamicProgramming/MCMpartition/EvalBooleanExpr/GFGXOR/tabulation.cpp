#include<bits/stdc++.h>
int MOD = 1000000007;
int evaluateExp(string & s) {
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    for(int i=0; i<=n-1; i+=2){
        dp[i][i][1] = (s[i]=='T');
        dp[i][i][0] = (s[i]=='F');
    }
    for(int i=n-1; i>=0; i-=2){
        for(int j=i+2; j<=n-1; j+=2){
            long long ansT = 0;
            long long ansF = 0;
            for(int ind=i+1; ind<=j-1; ind+=2){
                long long lt = dp[i][ind-1][1];
                long long lf = dp[i][ind-1][0];
                long long rt = dp[ind+1][j][1];
                long long rf = dp[ind+1][j][0];
                
                if(s[ind] == '&'){
                    ansT = (ansT + lt*rt % MOD) % MOD;
                    ansF = (ansF + (lt*rf)%MOD+(lf*rt)%MOD+(lf*rf)%MOD) % MOD;
                }
                else if(s[ind] == '|'){
                    ansT = (ansT + (lt*rt)%MOD+(lt*rf)%MOD+(lf*rt)%MOD) % MOD;
                    ansF = (ansF + lf*rf % MOD) % MOD;
                }
                else{
                    ansT = (ansT + (lt*rf)%MOD+(lf*rt)%MOD) % MOD;
                    ansF = (ansF + (lt*rt)%MOD+(lf*rf)%MOD) % MOD;
                }

            }
            dp[i][j][1] = (int)ansT%MOD;
            dp[i][j][0] = (int)ansF%MOD;
        }
    }
    return dp[0][n-1][1];
}