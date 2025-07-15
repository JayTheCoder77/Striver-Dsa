int kthLargest(Node *root, int k) {
    if (!root) return -1;
    
    Node* cur = root;
    int cnt = 0;
    int ans = -1;
    
    while (cur != NULL) {
        if (cur->right == NULL) {
            cnt++;
            if (cnt == k) ans = cur->data;
            cur = cur->left;
        } else {
            Node* succ = cur->right;
            while (succ->left && succ->left != cur) {
                succ = succ->left;
            }

            if (!succ->left) {
                succ->left = cur;
                cur = cur->right;
            } else {
                succ->left = NULL;
                cnt++;
                if (cnt == k) ans = cur->data;
                cur = cur->left;
            }
        }
    }

    return ans;
}


