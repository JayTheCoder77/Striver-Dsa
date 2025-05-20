// same sol but for other sites like gfg etc.
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double> res;
        priority_queue <int , vector<int> , greater<int>> minHeap; // large heap
        priority_queue <int> maxHeap; // small heap
        for (int i = 0; i < arr.size(); ++i) {
            int num = arr[i];
        
    
        maxHeap.push(num);
        // o(logn) heap operations
        // make sure every num in small is <= every num in large
        if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()){
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
        }
        // uneven size
        if(maxHeap.size() > minHeap.size() + 1){
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
        }
        if(minHeap.size() > maxHeap.size() + 1){
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
        }
    
    
        if(maxHeap.size() > minHeap.size()) res.push_back(maxHeap.top());
        else if(minHeap.size() > maxHeap.size()) res.push_back(minHeap.top());
        else res.push_back((maxHeap.top() + minHeap.top()) / 2.0);
    }
    return res;
    }
};
