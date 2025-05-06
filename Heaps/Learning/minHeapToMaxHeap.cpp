class Solution {
    public:
      void downheap(vector<int> &list , int n , int i) {
              int maxI = i;
              int l = 2 * i + 1;
              int r = 2 * i + 2;
              if (l < list.size() && list[l] > list[maxI]) maxI = l;
              if (r < list.size() && list[r] > list[maxI]) maxI = r;
              if (maxI != i) {
                  swap(list[i], list[maxI]);
                  downheap(list , n , maxI);
              }
          }
      void convertMinToMaxHeap(vector<int> &arr, int N) {
          int n = arr.size();

          // Start from the last non-leaf node and heapify each node
          for (int i = (n / 2) - 1; i >= 0; i--)
          downheap(arr, n, i);
      }
  };
