class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        vector<int> ans;
        priority_queue<pair<int,int>> maxHeap;
        for(int i = 0 ; i < nums.size() ; i++) mpp[nums[i]]++;
        for(auto const& pair_e : mpp)
            maxHeap.push({pair_e.second , pair_e.first});
        while(k > 0 && !maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
            k--;
        }
        return ans;
    }
};

tc = o(k logn)
sc = o(n)