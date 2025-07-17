TreeNode* insert(TreeNode* root , int val){
    if(!root) return new TreeNode(val);
    if(val < root -> data) root -> left = insert(root -> left , val);
    else if(val > root -> data) root -> right = insert(root -> right , val);
    return root;
}
TreeNode *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    TreeNode* root = NULL;
    for(int i = 0 ; i < preOrder.size() ; i++){
        root = insert(root , preOrder[i]);
    }
    return root;
}

tc = O(n^2)
sc = O(n)