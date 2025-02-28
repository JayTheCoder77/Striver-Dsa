void reverse(stack<int> &stack,int x){
    if(stack.empty()){
        stack.push(x);
        return;
    }
    int temp = stack.top();
    stack.pop();
    reverse(stack,x);
    stack.push(temp);
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()) return;
    int top = stack.top();
    stack.pop();
    reverseStack(stack);
    reverse(stack,top);
}

tc = o(n2)
sc = o(n)