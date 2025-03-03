class Solution {
    public:
        int subSeq(int ind,vector<int>&nums, int target,int n,int s){
            if(ind == n){
                if(s == target) return 1;
                else return 0;
            }
            
            
            int incl=subSeq(ind + 1 , nums , target , n , s + nums[ind]);
            
    
            int excl=subSeq(ind + 1 , nums , target , n , s);
            return incl + excl;
        }
        int numSubseq(vector<int>& nums, int target) {
            int n = nums.size();
            return subSeq(0,nums,target,n,0);
        }
    };

    tc = o(2^n)
    sc = o(n)