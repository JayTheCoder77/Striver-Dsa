class Solution {
    public:
    void generate(vector<int> &arr,vector<int> &ds,vector<vector<int>> &ans,int ind){
        ans.push_back(ds);
        for(int i = ind ; i < arr.size() ; i++){
            if(i != ind && arr[i] == arr[i-1]) continue;
            ds.push_back(arr[i]);
            generate(arr,ds,ans,i+1);
            ds.pop_back();
        }
    }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        generate(nums,ds,ans,0);
        return ans;
        }
    };

tc = o(nlogn) sort + o(2^n * n) to store in ans ds 
sc = o(2^n * k) k is subset length  + o(n) recursion