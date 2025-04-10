class Solution {
    public:
      int priority(char s){
          if(s == '^') return 3;
          else if(s == '*' || s == '/') return 2;
          else if(s == '+' || s == '-') return 1;
          return -1;
      }
      string infixToPostfix(string& s) {
          // code here
          stack <char> s1;
          string ans = "";
          for(int i = 0 ; i < s.length() ; i++){
  if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) ans += s[i];
              else if(s[i] == '(') s1.push(s[i]);
              else if(s[i] == ')'){
                  while(!s1.empty() && s1.top() != '('){
                      ans += s1.top();
                      s1.pop();
                  }
                  if(!s1.empty()) {
                      s1.pop(); 
                  }
              }
              else{
                  while(!s1.empty() && priority(s[i]) <= priority(s1.top())){
                      ans += s1.top();
                      s1.pop();
                  }
                  s1.push(s[i]);
              }
          }
          while(!s1.empty()){
              ans += s1.top();
              s1.pop();
          }
          return ans;
      }
  };
  
  tc = o(n) + o(n)
  sc = o(n) + o(n)