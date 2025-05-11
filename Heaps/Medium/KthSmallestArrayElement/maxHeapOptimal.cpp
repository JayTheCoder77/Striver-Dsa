class Solution {
    public:
      // arr : given array
      // k : find kth smallest element and return using this function
      int kthSmallest(vector<int> &nums, int k) {
          // code here
              // priority_queue<int> maxHeap; can also use this as less<int> is default
              priority_queue<int , vector<int> , less<int>> maxHeap;
              for(int num : nums){
                  maxHeap.push(num);
                  if(maxHeap.size() > k) maxHeap.pop();
              }
              return maxHeap.top();
          }
  };
