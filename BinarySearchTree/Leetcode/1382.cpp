1382. Balance a Binary Search Tree

class Solution {
public:
    void inorder(TreeNode* root , vector<int>& ans){
        if(!root) return;
        inorder(root -> left , ans); 
        ans.push_back(root -> val);
        inorder(root -> right , ans); 
    }
    TreeNode* build(vector<int>& ans , int l , int r){
        if(l > r) return NULL;
        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode(ans[m]);
        root -> left = build(ans , l , m - 1);
        root -> right = build(ans , m + 1 , r);
        return root;
    } 
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root , nodes); 
        return build(nodes , 0 , nodes.size() - 1);
    }
};