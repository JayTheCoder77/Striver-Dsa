// brute - just normally sort using merge sort - n log n
// optimal - use heap - n log k

class Solution {
    public:
      void nearlySorted(vector<int>& arr, int k) {
          // code
          int i = 0 , j = 0;
          // minHeap
          priority_queue<int,vector<int>,greater<int>> minHeap;
          while(j < arr.size()){
              minHeap.push(arr[j]);
              if(minHeap.size() > k){
                  arr[i] = minHeap.top();
                  minHeap.pop();
                  i++;
              }
              j++;
          }
          while(!minHeap.empty()){
              arr[i] = minHeap.top();
              minHeap.pop();
              i++;
          }
      }
  };

  tc = o(n logk)
  sc = o(k)
