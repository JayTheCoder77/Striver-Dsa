class Solution {
    public:
      string preToInfix(string s) {
          // Write your code here
          stack<string> s1;
          for(int i = s.length() - 1; i >= 0 ; i--){
              if((s[i] >= 'A' && s[i] <= 'Z') 
               || (s[i] >= 'a' && s[i] <= 'z') 
               || (s[i] >= '0' && s[i] <= '9')) s1.push(string(1,s[i]));
              else{
                    string t1 = s1.top();
                    s1.pop();
                    string t2 = s1.top();
                    s1.pop();
                    string res = '(' + t1 + s[i] + t2 + ')';
                    s1.push(res);
              }
          }
          return s1.top();
      }
  };

  tc = o(n) + o(n1+n2)
  sc = o(n) 