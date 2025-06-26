class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
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
                if(i == 0) res.push_back(node -> data);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};