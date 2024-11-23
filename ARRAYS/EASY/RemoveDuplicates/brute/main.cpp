class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int,int> hash;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            hash.insert(nums[i]);
        }
        int j = 0;
        for(auto it : hash){
            nums[j++] = it;
        }
        return j;
    }
};

tc o(n log n) + o (n)

sc o(n)