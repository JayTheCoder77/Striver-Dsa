vector<int> replaceWithRank(vector<int> &arr, int n) {
    // Write your code here.
    if (n == 0) return {};
    
    // Create pairs of (value, original index)
    vector<pair<int, int>> valWithIdx;
    for (int i = 0; i < n; i++) {
        valWithIdx.push_back({arr[i], i});
    }
    
    // Use min heap to sort the pairs by value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (auto& p : valWithIdx) {
        minHeap.push(p);
    }
    
    // Process the sorted elements
    vector<int> result(n);
    int rank = 0;
    int prevVal = INT_MIN;
    
    while (!minHeap.empty()) {
        pair<int, int> top = minHeap.top();
    int val = top.first;
    int idx = top.second;
        minHeap.pop();
        
        // Assign new rank only if value changes
        if (val != prevVal) {
            rank++;
            prevVal = val;
        }
        
        result[idx] = rank;
    }
    
    return result;

}
