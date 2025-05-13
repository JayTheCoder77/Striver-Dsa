class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted (arr.begin() , arr.end());
        sort(sorted.begin() , sorted.end());
        unordered_map<int,int> hash;
        int rank = 1;
        for(int i = 0 ; i < arr.size() ; i++){
            if(hash.find(sorted[i]) == hash.end()){
            hash[sorted[i]] = rank++;
            }
        }
        vector<int> ans(arr.size());
        for(int i = 0 ; i < arr.size() ; i++){
            ans[i] = hash[arr[i]];
        }
        return ans;
    }
};

tc = o(nlogn)
sc = o(n)