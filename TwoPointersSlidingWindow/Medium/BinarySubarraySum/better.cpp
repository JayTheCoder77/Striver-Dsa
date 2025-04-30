optimal case of subarray sum k will become better for this
class Solution {
    public:
      int numberOfSubarrays(vector<int>& arr, int target) {
          // Your code goes here.
     map <int,int> mpp;
          mpp[0] = 1;
          int preSum = 0;
          int count = 0;
          int n = arr.size();
          for(int i = 0 ; i < n ; i++){
              preSum += arr[i];
              int remove = preSum - target;
              count += mpp[remove];
              mpp[preSum] += 1;
          }
          return count;
      }
  };