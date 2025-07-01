class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {
        // Your code here
        if (!root) return 0;
        queue<Node*> q;
        q.push(root);
        int maxWidth = 0;
        while(!q.empty()){
            int size = q.size();
            maxWidth = max(maxWidth, size);
            for(int i = 0 ; i < size ; i++){
                Node* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return maxWidth;
    }
};