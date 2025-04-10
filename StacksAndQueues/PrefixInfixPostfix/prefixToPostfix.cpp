class Solution {
    public:
      string preToPost(string s) {
          stack<string>s1;
          for(int i = s.length()-1 ; i >= 0 ; i--){
              if((s[i] >= 'A' && s[i] <= 'Z') 
                 || (s[i] >= 'a' && s[i] <= 'z') 
                 || (s[i] >= '0' && s[i] <= '9')) s1.push(string(1,s[i]));
              else{
                  string top1 = s1.top();
                  s1.pop();
                  string top2 = s1.top();
                  s1.pop();
                  string res = top1 + top2 + s[i];
                  s1.push(res);
              }
          }
          return s1.top();
      }
  };

  tc = o(2n)
  sc = 0(n)