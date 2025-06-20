class Solution
{
public:
    int ht(TreeNode *node, int &maxi)
    {
        if (node == NULL)
            return 0;
        int lh = ht(node->left, maxi);
        int rh = ht(node->right, maxi);
        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        ht(root, diameter);
        return diameter;
    }
};
tc = o(n)
sc = o(n)