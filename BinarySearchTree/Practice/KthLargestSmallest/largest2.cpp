
int kthSmallest(Node* root, int k) {
        TreeNode* cur = root;
        int cnt = 0 , ans = 0;
        while(cur != NULL){
            // 1st case
            if(cur -> left == NULL){
                cnt++;
                if (cnt == k) ans = cur->val;
                cur = cur -> right;
            }
            // 2nd case
            else{
                TreeNode* prev = cur -> left;
                while(prev -> right && prev -> right != cur){
                    prev = prev -> right;
                }
                if(!prev -> right){
                    prev -> right = cur;
                    cur = cur -> left;
                }
                else{
                    prev -> right = NULL;
                    cnt++;
                    if(cnt == k) ans = cur -> val;
                    cur = cur -> right;
                }
            }
        }
        return ans;
    }

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int kthLargest(Node *root, int k) {
    int total = countNodes(root);
    if (k > total) return -1;
    return kthSmallest(root, total - k + 1);
}
