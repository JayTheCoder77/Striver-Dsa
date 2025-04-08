#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		stack<pair<int,int>> s1;
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			if(s1.empty()) s1.push({num,num});
			else s1.push({num , min(num,s1.top().second)});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(s1.empty()) return -1;
			pair<int,int> old = s1.top();
			s1.pop();
			return old.first;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(s1.empty()) return -1;
			return s1.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(s1.empty()) return -1;
			return s1.top().second;
		}
};

tc = o(1)
sc = o(2n)