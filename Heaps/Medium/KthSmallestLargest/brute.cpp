#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &nums, int n, int k)
{
	// Write your code here.
	vector<int> res;
	// smallest
	 priority_queue<int , vector<int> , less<int>> maxHeap;
              for(int num : nums){
                  maxHeap.push(num);
                  if(maxHeap.size() > k) maxHeap.pop();
              }
              res.push_back(maxHeap.top());

		// largest
	 priority_queue<int , vector<int> , greater<int>> minHeap;
            for(int num : nums){
                minHeap.push(num);
                if(minHeap.size() > k) minHeap.pop();
            }
            res.push_back(minHeap.top());
			return res;
}
