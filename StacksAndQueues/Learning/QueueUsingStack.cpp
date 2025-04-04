// when there are more elements to push
class MyQueue {
    public:
        stack<int> s1;
        stack<int> s2;
    
        MyQueue() {
    
        }
        
        void push(int x) {
            s1.push(x);
        }
        
        int pop() {
           if (s2.empty()) {
                // Transfer elements from s1 to s2
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            
            int result = s2.top();
            s2.pop();
            return result;
        }
        
        int peek() {
            if(!s2.empty()) return s2.top();
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
        
        bool empty() {
            if(s2.empty() && s1.empty()) return true;
            return false;
        }
    };
    
    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue* obj = new MyQueue();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->peek();
     * bool param_4 = obj->empty();
     */

tc = 0(2n) for pop top o(1) for push
sc = dynamic 



// other implementation  when there are lesser elements to push

#include <bits/stdc++.h>

using namespace std;

struct Queue {
  stack < int > input, output;
  
  // Push elements in queue
  void Push(int data) {
    // Pop out all elements from the stack input
    while (!input.empty()) {
      output.push(input.top());
      input.pop();
    }
    // Insert the desired element in the stack input
    cout << "The element pushed is " << data << endl;
    input.push(data);
    // Pop out elements from the stack output and push them into the stack input
    while (!output.empty()) {
      input.push(output.top());
      output.pop();
    }
  }
  // Pop the element from the Queue
  int Pop() {
    if (input.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    int val = input.top();
    input.pop();
    return val;
  }
  // Return the Topmost element from the Queue
  int Top() {
    if (input.empty()) {
      cout << "Stack is empty";
      exit(0);
    }
    return input.top();
  }
  // Return the size of the Queue
  int size() {
    return input.size();
  }
};
int main() {
  Queue q;
  q.Push(3);
  q.Push(4);
  cout << "The element poped is " << q.Pop() << endl;
  q.Push(5);
  cout << "The top of the queue is " << q.Top() << endl;
  cout << "The size of the queue is " << q.size() << endl;
}

tc = o(2n) for pushing o(1) for pop top
sc = dynamic