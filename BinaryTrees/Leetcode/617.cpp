// leetcode 617 - merge two binary trees

class Solution {
public:
    // preorder dfs
    TreeNode* dfs(TreeNode* node1, TreeNode* node2){
        if(!node1) return node2;
        if(!node2) return node1;
        TreeNode* node = new TreeNode(node1 -> val + node2 -> val);
        node -> left = dfs(node1 -> left , node2 -> left);
        node -> right = dfs(node1 -> right , node2 -> right);
        return node;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        TreeNode* root = dfs(root1 , root2);
        return root;
    }
};


// merging in place instead of creating a new binary tree

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};