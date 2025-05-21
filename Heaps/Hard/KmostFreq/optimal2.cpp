bucket sort / counting sort

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < nums.size() ; i++) mpp[nums[i]]++;
        vector<vector<int>> count (nums.size() + 1);
        for(auto const& e : mpp) count[e.second].push_back(e.first);
        vector<int> ans;
        for(int i = nums.size() ; i >= 0 && ans.size() < k ; i--){
            for(int num : count[i]){
                ans.push_back(num);
                if(ans.size() == k) break;
            }
        }
        return ans;
    } 
};


tc = o(n)
sc = o(n)