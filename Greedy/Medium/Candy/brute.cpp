class Solution {
    public:
      int minCandy(vector<int> &arr) {
          // code here
          int n = arr.size();
          int left[n] , right[n];
          left[0] = 1 , right[n-1] = 1;
          for(int i = 1 ; i < n ; i++){
              if(arr[i] > arr[i-1]) left[i] = left[i-1] + 1;
              else left[i] = 1;
          }
          for(int i = n-2 ; i >= 0 ; i--){
              if(arr[i] > arr[i+1]) right[i] = right[i+1] + 1;
              else right[i] = 1;
          }
          int sum = 0;
          for(int i = 0 ; i < n ; i++){
              sum += max(left[i] , right[i]);
          }
          return sum;
      }
  };


tc = o(3n)
sc = o(2n)
