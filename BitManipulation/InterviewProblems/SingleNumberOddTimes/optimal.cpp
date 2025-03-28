class Solution {
    public:
      int getSingle(vector<int>& arr) {
          // code here
          int xor1 = 0;
          for(int i = 0 ; i < arr.size() ; i++){
              xor1 = xor1 ^ arr[i];
          }
          return xor1;
      }
  };

  tc = o(n)
  sc = o(1)