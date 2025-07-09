class Solution {
public:
    void flatten(TreeNode* root) {
        // preorder root left right
        // 1 recursion 2. stack 3. morris 
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur -> left){
                TreeNode* prev = cur -> left;
                while(prev -> right) prev = prev -> right;
                prev -> right = cur -> right;
                cur -> right = cur -> left;
                cur -> left = NULL;
            }
            cur = cur -> right;
        }
    }
};