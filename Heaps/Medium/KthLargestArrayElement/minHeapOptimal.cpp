class Solution {
    public:
        // min heap version - optimal - priority queue
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int , vector<int> , greater<int>> minHeap;
            for(int num : nums){
                minHeap.push(num);
                if(minHeap.size() > k) minHeap.pop();
            }
            return minHeap.top();
        }
    };

    tc = o(n logk)
    sc = o(k)
