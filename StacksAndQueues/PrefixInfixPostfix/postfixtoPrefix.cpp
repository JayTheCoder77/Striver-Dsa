#include <bits/stdc++.h>
string postfixToPrefix(string &s){
    // Write your code here.
    stack<string>s1;
        for(int i = 0 ; i < s.length() ; i++){
            if((s[i] >= 'A' && s[i] <= 'Z') 
               || (s[i] >= 'a' && s[i] <= 'z') 
               || (s[i] >= '0' && s[i] <= '9')) s1.push(string(1,s[i]));
            else{
                string top1 = s1.top();
                s1.pop();
                string top2 = s1.top();
                s1.pop();
                string res = s[i] + top2 + top1;
                s1.push(res);
            }
        }
        return s1.top();
}

tc = 0(2n)
sc = 0(n)

// brute
postfix to infix then infix to prefix