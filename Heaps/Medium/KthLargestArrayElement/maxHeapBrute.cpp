class Solution {
    public:
        void heapify(vector<int>& arr, int n , int i){
            int largest = i;       // Initialize largest as root
            int left = 2 * i + 1;   // Left child
            int right = 2 * i + 2;  // Right child
            if (left < n && arr[left] > arr[largest])
            largest = left;

            if (right < n && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                heapify(arr,n,largest);
            }
        }
        int findKthLargest(vector<int>& nums, int k) {
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

    tc = o(n) + o(klogn)
    sc = o(1)
