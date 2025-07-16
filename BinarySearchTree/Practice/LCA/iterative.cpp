class Solution {
  public:
    Node* LCA(Node* root, Node* p, Node* q) {
        // code here
        if(root == NULL) return NULL;
        while(root){
            int curr = root -> data;
            if(curr < p -> data && curr < q -> data){
                root = root -> right;
            }
            else if(curr > p -> data && curr > q -> data){
                root = root -> left;
            }
            else{
                return root;
            }
        }
        return root;
    }
};

