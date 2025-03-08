leetcode 90 bruteforce

class Solution {
    public:
        void generate(vector<int> &nums , set<vector<int>> &ans , vector<int> &res , int ind){
            if(ind >= nums.size()){
                ans.insert(res);
                return;
            }
            // pick
            res.push_back(nums[ind]);
            generate(nums,ans,res,ind+1);
            // not pick
            res.pop_back();
            generate(nums,ans,res,ind+1);
        }
        vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
            // Write your code here
            set<vector<int>> ans;
            vector<int> res;
            sort(nums.begin(),nums.end());
            generate(nums,ans,res,0);
            vector<vector<int>> final(ans.begin(), ans.end());
            return final;
        }
    };

tc = o(nlogn) sort arr + o(2^n * k(log(2^n))) 2^n for choice and k log 2^n for insert in set where k is len of subsets 
 
tc boils down to o(2^n log (2^n))

sc = o(2^n * n) for storing unique subsets + o(n) for recursion

sc boils down to o(2^n * n)