#include<bits/stdc++.h>
void generate(int i ,string &s , string &temp,vector<string> &ans,unordered_map<char,string> &mpp){
	// backtracking
	if(i == s.size()){
		ans.push_back(temp);
		return;
	}
	string str = mpp[s[i]];
	for(int j = 0 ; j < str.size() ; j++){
		temp.push_back(str[j]);
		generate(i+1,s,temp,ans,mpp);
		temp.pop_back();
	}
}
vector<string> combinations(string s){
	// Write your code here
	vector<string> ans;
	unordered_map<char,string> mpp;
	string temp = "";
	mpp['2'] = "abc";
	mpp['3'] = "def";
	mpp['4'] = "ghi";
	mpp['5'] = "jkl";
	mpp['6'] = "mno";
	mpp['7'] = "pqrs";
	mpp['8'] = "tuv";
	mpp['9'] = "wxyz";
	generate(0,s,temp,ans,mpp);
	return ans;
}

tc = o(4^n)
tc = o(4^n) + o(n)