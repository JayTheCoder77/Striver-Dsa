class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // dfs 
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root -> left , p , q);
        TreeNode* right = lowestCommonAncestor(root -> right , p , q);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        // left and right arent null
        else return root;
    }
};