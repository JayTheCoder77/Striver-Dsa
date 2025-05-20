class MedianFinder {
public:
    priority_queue <int , vector<int> , greater<int>> minHeap; // large heap
    priority_queue <int> maxHeap; // small heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
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
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) return (double)maxHeap.top();
        if(minHeap.size() > maxHeap.size()) return (double)minHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

tc = o(logn) 
sc = o(n)

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */