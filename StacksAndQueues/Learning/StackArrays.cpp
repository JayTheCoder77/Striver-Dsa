// question (implementation below)
class Stack {
    
private:
    int* st;         // Array to store stack elements
    int topIndex;    // Index of the top element
    int capacity;    // Maximum capacity of the stack
    
public:
    Stack(int cap) {
        capacity = cap;
        st = new int[capacity];
        topIndex = -1;
    }
    
    

    void push(int num) {
        if(!isFull()) {
            topIndex++;
            st[topIndex] = num;
        }
    }

    int pop() {
        if(isEmpty()) {
            return -1;  // Or handle the error differently
        }
        int old = st[topIndex];
        topIndex--;
        return old;
    }
    
    int top() {
        if(topIndex == -1) return -1;
        return st[topIndex];
    }
    
    int isEmpty() {
        if(topIndex == -1) return 1;
        return 0;
    }
    int size(){
        return top + 1;
    }
    int isFull() {
        if(topIndex == capacity - 1) return 1;  // Note: -1 because indices start at 0
        return 0;
    }
    
};

tc = 0(1)
sc = 0(capacity)

// implementation

#include<bits/stdc++.h>

using namespace std;
class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }
  void push(int x) {
    top++;
    arr[top] = x;
  }
  int pop() {
    int x = arr[top];
    top--;
    return x;
  }
  int Top() {
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
};
int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}