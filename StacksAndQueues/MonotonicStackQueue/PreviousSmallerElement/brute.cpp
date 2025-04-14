class Solution {
    public:
      vector<int> leftSmaller(vector<int> arr) {
          // code here
          vector<int> nse(arr.size(),-1);
          for(int i = arr.size()-1 ; i >= 0 ; i--){
              bool found = false;
              for(int j = i-1 ; j >= 0 ; j--){
                  if(arr[j] < arr[i]){
                      found = true;
                      nse[i] = arr[j];
                      break;
                  }
              }
          }
          return nse;
      }
  };

  tc =o (n2)
  sc = o(n) to return ans