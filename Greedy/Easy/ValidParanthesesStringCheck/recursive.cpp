naive brute solution

better is dp memoization and tabulation

#include <bits/stdc++.h> 
bool generate(string &s ,int ind , int cnt){
	if(cnt < 0) return false;
	if(ind == s.length()) return cnt == 0;
	if(s[ind] == '(') return generate(s , ind + 1, cnt + 1);
	if(s[ind] == ')') return generate(s , ind + 1, cnt - 1);
	if(s[ind] == '*'){
		return generate(s , ind + 1, cnt + 1) || generate(s , ind + 1, cnt - 1) || generate(s , ind + 1, cnt);
	}
}
bool checkValidString(string &s){
	// Write your code here.
	// recursion
	return generate(s , 0 , 0);
}

tc = o(3^n)
stack space
sc = o(n)