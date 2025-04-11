class Solution {
    public:
      vector<int> nextLargerElement(vector<int>& arr) {
          // code here
            int n = arr.size();
            stack<int> s;
            vector<int> nge (n,-1);
            for(int i = arr.size()-1 ; i >= 0 ; i--){
                while(!s.empty() && s.top() <= arr[i]){
                        s.pop();
                   }
                  if(s.empty()) nge[i] = -1;
                  else nge[i] = s.top();
              s.push(arr[i]);
              }
           return nge;
      }
  };

  tc = o(2n)
  sc = o(n) + o(n)