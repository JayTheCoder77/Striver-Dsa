class Solution {
    public:
      string postToInfix(string s) {
          // Write your code here
          stack<string> s1;
          for(int i = 0 ; i < s.length() ; i++){
              if((s[i] >= 'A' && s[i] <= 'Z') 
              || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) s1.push(string(1,s[i]));
              else{
                  string t2 = s1.top();
                  s1.pop();
                  string t1 = s1.top();
                  s1.pop();
                  string res = '(' + t1 + s[i] + t2 + ')';
                  s1.push(res);
              }
          }
          return s1.top();
      }
  };

  tc = o(n) + o(n)
  sc = o(n)