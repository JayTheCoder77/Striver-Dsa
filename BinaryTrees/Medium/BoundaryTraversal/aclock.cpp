class Solution {
  public:
    void addLeft(Node *node , vector<int> &res){
        Node* cur = node -> left;
        while(cur){
            if(!isLeaf(cur)) res.push_back(cur->data);
            if(cur -> left) cur = cur -> left;
            else cur = cur -> right;
        }
    }
    void addRight(Node *root , vector<int> &res){
        Node* cur = root -> right;
        vector<int> tmp;
        while(cur){
            if(!isLeaf(cur)) tmp.push_back(cur->data);
            if(cur -> right) cur = cur -> right;
            else cur = cur -> left;
        }
        for(int i = tmp.size() - 1 ; i >= 0 ; i--) res.push_back(tmp[i]);
    }
    void addLeaves(Node *root , vector<int> &res){
        if(isLeaf(root)){
            res.push_back(root -> data);
            return;
        }
        if(root -> left) addLeaves(root -> left , res);
        if(root -> right) addLeaves(root -> right , res);
    }
    bool isLeaf(Node* root){
        return root -> left == NULL && root -> right == NULL;
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root -> data);
        addLeft(root,res);
        addLeaves(root,res);
        addRight(root,res);
        return res;
    }
};