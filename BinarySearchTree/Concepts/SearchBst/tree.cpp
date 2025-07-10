class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root -> val == val) return root;
        if(val > root -> val) return searchBST(root -> right , val);
        return searchBST(root -> left , val);
    }
};

tc = o(logn base2)
sc = o(logn base2)


// iterative version

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    while (root != NULL && root -> data != x){
        root = x < root -> data ? root -> left : root -> right;
    }
    return root;
}

tc = o(logn base2)
sc = o(1)