class Solution {
    public:
      int minCandy(vector<int> &arr) {
          // code here
          int n = arr.size();
          vector<int> left(n , 1);
          left[0] = 1;
          for(int i = 1 ; i < n ; i++){
              if(arr[i] > arr[i-1]) left[i] = left[i-1] + 1;
              else left[i] = 1;
          }
          int curr = 1 , right = 1;
          int sum = max(1,left[n-1]);
          for(int i = n-2 ; i >= 0 ; i--){
              if(arr[i] > arr[i+1]){
                  curr = right + 1;
                  right = curr;
              }
              else{
                  curr = 1;
                  right = 1;
              }
              sum = sum + max(left[i] , curr);
          }
          return sum;
      }
  };


  tc = o(2n)
  sc = o(n)