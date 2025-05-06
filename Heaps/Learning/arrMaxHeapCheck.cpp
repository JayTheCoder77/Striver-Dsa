class Solution {
    public:
      bool isMaxHeap(int arr[], int n) {
          // Your code goes here
          for(int i = 0 ; i < n ; i++){
              int largest = i;
              int left = 2 * i + 1;   // Left child
              int right = 2 * i + 2;  // Right child
              if (left < n && arr[largest] < arr[left])
                  return false;

              if (right < n && arr[largest] < arr[right])
                  return false;
          }
          return true;
      }
  };
