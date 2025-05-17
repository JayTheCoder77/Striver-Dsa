class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue <int , vector<int> , greater<int>> minHeap;
        for(int i = 0 ; i  < arr.size() ; i++) minHeap.push(arr[i]);
        int minCost = 0;
        while(minHeap.size() > 1){
            int top1 = minHeap.top();
            minHeap.pop();
            int top2 = minHeap.top();
            minHeap.pop();
            int cost = top1 + top2;
            minCost += cost;
            minHeap.push(cost);
        }
        return minCost;
    }
};