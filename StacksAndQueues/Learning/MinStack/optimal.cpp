class MinStack {
    public:
        stack<long long> s1;
        long long mini;
        MinStack() {
            mini = INT_MAX;
        }
        
        void push(int val) {
            if(s1.empty()){
                mini = val;
                s1.push(val);
            }
            else{
                if(val < mini){
                    long long modified =  (long long)val * 2 - mini;
                    s1.push(modified);
                    mini = val;
                }
                else s1.push(val);
            }
        }
        
        void pop() {
            if(s1.empty()) return;
            long long a = s1.top();
            s1.pop();
            if(a < mini) mini = 2 * mini - a;
            if(s1.empty()) mini = INT_MAX;
        }
        
        int top() {
            if(s1.empty()) return -1;
            long long a = s1.top();
            return a < mini  ? mini : a;
        }
        
        int getMin() {
            if(s1.empty()) return -1;
            return mini;   
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */

     tc = o(1)
     sc = o(n)