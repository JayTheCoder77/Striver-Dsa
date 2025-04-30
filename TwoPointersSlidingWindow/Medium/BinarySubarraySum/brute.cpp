
this is brute 

class Solution {
    public:
      int numberOfSubarrays(vector<int>& arr, int target) {
          // Your code goes here.
          int count = 0;
          for(int i = 0 ; i < arr.size() ; i++){
          int sum = 0;
              for(int j = i ; j < arr.size() ; j++){
                  sum += arr[j];
                  if(sum == target) count++;
              }
          
          }
          return count;
      }
  };

  tc = o(n2)
  sc = o(1)