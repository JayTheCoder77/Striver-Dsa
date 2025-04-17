class Solution {
    public:
        string removeKdigits(string num, int k) {
            // Write your code here.
        // greedy approach
        if(k >= num.length()) return "0";
        stack<char> s;
        for(int i = 0 ; i < num.length() ; i++){
            while(!s.empty() && s.top() > num[i] && k > 0){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k > 0){
             s.pop();
             k--;
        }
        string res = "";
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        while(res.size() != 0 && res.back() == '0') res.pop_back();
        reverse(res.begin() ,res.end());
        return res.empty() ? "0" : res;
        }
    };

    tc = o(n) 
    sc = o(n)