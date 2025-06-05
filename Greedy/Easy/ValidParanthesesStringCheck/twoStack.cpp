#include <bits/stdc++.h> 
bool checkValidString(string &s){
	// Write your code here.
	stack<int> s1;
        stack<int> s2;
        int index = 0;
        for(auto c : s){
            if(c == '('){
                s1.push(index);
            }
            else if(c == '*'){
                s2.push(index);
            }
            else if(c == ')'){
                if(!s1.empty()) s1.pop();gi
                else if(!s2.empty()) s2.pop();
                else return false;
            }
            index++;
        }
        // Now try to match any remaining '(' with '*' that come after it
        while (!s1.empty() && !s2.empty()) {
            if (s2.top() > s1.top()) {
                s1.pop();
                s2.pop();
            } 
            else break; // '*' comes before '(', invalid
        }
        return s1.empty();
}