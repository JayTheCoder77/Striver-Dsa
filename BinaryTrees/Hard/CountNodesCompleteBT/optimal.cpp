class Solution {
public:
    // no of nodes in full complete bt = 2^height - 1
    // last level in complete bt may not be filled completely and last lvl will be filled from left side
    // so applying formula for subtrees and adding them up
    int leftHt(TreeNode* node){
        int lh = 0;
        while(node){
            lh++;
            node = node -> left;
        }
        return lh;
    }
    int rightHt(TreeNode* node){
        int rh = 0;
        while(node){
            rh++;
            node = node -> right;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = leftHt(root);
        int rh = rightHt(root);
        // 2 ^ ht - 1 => bit manip 1 << lh
        if(lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};

tc = o(logn)2
sc = o(logn)