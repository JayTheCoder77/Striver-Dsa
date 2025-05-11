class Solution {
    public:
      // arr : given array
      // k : find kth smallest element and return using this function
       void heapify(vector<int>& arr, int n , int i){
              int smallest = i;       // Initialize smallest as root
              int left = 2 * i + 1;   // Left child
              int right = 2 * i + 2;  // Right child
              if (left < n && arr[left] < arr[smallest])
              smallest = left;

              if (right < n && arr[right] < arr[smallest])
                  smallest = right;

              if (smallest != i) {
                  swap(arr[i], arr[smallest]);
                  heapify(arr,n,smallest);
              }
          }
      int kthSmallest(vector<int> &nums, int k) {
          // code here
              int n = nums.size();
              if (k <= 0 || k > n) return -1;
              int lastNonLeaf = (n / 2) - 1;
              for(int i = lastNonLeaf ; i >= 0 ; i--){
                  heapify(nums,n ,i);
              }

              for(int i = n - 1 ; i >= n - k + 1 ; i--){
                  swap(nums[0] , nums[i]);
                  heapify(nums , i , 0);
              }
              return nums[0];
          }
  };
