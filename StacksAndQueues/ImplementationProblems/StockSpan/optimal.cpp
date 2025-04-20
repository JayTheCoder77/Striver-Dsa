class StockSpanner {
    public:
        stack<pair<int,int>> s;
        int ind;
        StockSpanner() {
            ind = -1;
            while (!s.empty()) {
                s.pop();
            }
        }
        int next(int price) {
            ind += 1;
            // pop lower prices
            while(!s.empty() && s.top().first <= price) s.pop();
            int ans = ind - (s.empty() ? -1 : s.top().second);
            s.push({price , ind});
            return ans;
        }
    };


// normal

class Solution {
    public:
      vector<int> calculateSpan(vector<int>& arr) {
          // write code here
      stack<pair<int,int>> s;
  
      vector<int> days(arr.size() ,1);
      for(int i = 0 ; i < arr.size() ; i++){
         while(!s.empty() && s.top().first <= arr[i]) s.pop();
          int ans = i - (s.empty() ? -1 : s.top().second);
          days[i] = ans;
          s.push({arr[i] , i});
      }
      return days;
  }
  
  };

  tc = o(2n)
  sc = o(n)
