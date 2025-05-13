class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int n) {
        if(n == 0) return {};
        set<int> uniqueElements(arr.begin() , arr.end());
        unordered_map<int , int> ranks;
        int rank = 1;
        // assign ranks
        for(const int &e : uniqueElements){
            ranks[e] = rank++;
        }
        
        vector<int> ans;
        // find rank
        for(int &e : arr){
            ans.push_back(ranks[e]);
        }
        return ans;
    }
};

tc = o(n log n)
sc = o(n)