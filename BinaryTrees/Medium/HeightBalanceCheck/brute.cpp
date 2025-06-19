/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int findHleft(TreeNode<int>* node){
    if(node == NULL) return 0;
    int lh = findHleft(node -> left);
    int rh = findHleft(node -> right);
    return 1 + max(lh , rh);
}
int findHright(TreeNode<int>* node){
    if(node == NULL) return 0;
    int lh = findHright(node -> left);
    int rh = findHright(node -> right);
    return 1 + max(lh , rh);
}
bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.
    // naive solution
    if(root == NULL) return true;
    int lh = findHleft(root -> left);
    int rh = findHright(root -> right);
    if(abs(rh-lh) > 1) return false;
    bool left = isBalancedBT(root -> left);
    bool right = isBalancedBT(root -> right);
    if(!left || !right) return false;
    return true;
}

tc = o(n2)
sc = o()