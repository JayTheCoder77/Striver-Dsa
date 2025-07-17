TreeNode* build(vector<int>& preorder, int preS, int preE,
                    vector<int>& inorder, int inS, int inE,
                    map<int, int>& mpp) {
        if (preS > preE || inS > inE)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preS]);

        int inRoot = mpp[root->data];
        int numsLeft = inRoot - inS;

        root->left = build(preorder, preS + 1, preS + numsLeft, inorder, inS,
                           inRoot - 1, mpp);
        root->right = build(preorder, preS + numsLeft + 1,preE ,inorder,
                           inRoot + 1, inE , mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root = build(preorder, 0, preorder.size() - 1, inorder, 0,
                               inorder.size() - 1, mpp);
        return root;
    }
TreeNode *preOrderTree(vector<int> &preorder)
{
    // Write your code here.
     vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    return buildTree(preorder , inorder);
}

tc = O(nlogn)
sc = O(n)