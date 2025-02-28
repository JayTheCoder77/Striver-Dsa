#include <bits/stdc++.h> 
void add(stack<int> &s , int x){
	stack<int> temp;
	while(!s.empty() && s.top() >= x){
		temp.push(s.top());
		s.pop();
	}
	s.push(x);
	while(!temp.empty()){
		s.push(temp.top());
		temp.pop();
	}
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()) return;
	int top = stack.top();
	stack.pop();
	sortStack(stack);
	add(stack,top);
}

tc = o(n2)
sc = o(n)