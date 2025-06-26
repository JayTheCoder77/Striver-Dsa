class Solution {
  public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        // Your Code here
        vector<int> res;
        if(!root) return res;
        queue <Node*> q;
        q.push(root);
        while(!q.empty()){
            int qLen = q.size();
            for(int i = 0 ; i < qLen ; i++){
                Node* node = q.front();
                q.pop();
                // Capture the rightmost node at this level
                if(i == qLen - 1) res.push_back(node -> data);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};