class Solution {
    private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root -> left);

        if(prev != NULL && (root -> val < prev -> val)){
            // if this is the first violation mark nodes as first and middle
            if(first == NULL){
                first = prev;
                middle = root;
            }

            // if(secod violation then mark as last)
            else last = root;
        }
        prev = root;
        inorder(root -> right);
    }

    public:
    // brute - inorder - sort - build from sorted array

    // better - inorder - sort - pointers in array and bst

    // optimal - 2 cases - swapped nodes are adjacent / non adjacent
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first -> val , last -> val);
        else if(first && middle) swap(first -> val , middle -> val);
    }
};