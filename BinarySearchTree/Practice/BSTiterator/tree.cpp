class BSTIterator {
public:
    // naive - store inorder
    // tc = o(1)  sc = o(n)

    // optimal - dont store inorder
    // iterative inorder but storing only o(h)
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        while(root){
            s.push(root);
            root = root -> left;
        }
    }
    
    int next() {
        TreeNode* node = s.top();
        int a = node -> val;
        s.pop();
        if(node -> right){
            node = node -> right;
            while(node){
                s.push(node);
                node = node -> left;
            }
        }
        return a;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

tc = o(n) / o(n) = o(1)
sc = o(h)