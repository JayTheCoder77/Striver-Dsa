// 108 - build bst from sorted array

class Solution {
public:
    TreeNode* helper(vector<int>& nums , int l , int r){
        if(l > r) return NULL;
        int m = l + (r - l)  / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root -> left = helper(nums , l , m - 1);
        root -> right = helper(nums , m + 1 , r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums , 0 , nums.size() - 1);
    }
};

