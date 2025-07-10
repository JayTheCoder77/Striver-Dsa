class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        if(!root) return 0;
        while(root -> left != NULL){
            root = root -> left;
        }
        return root -> data;
    }
};

class Solution {
  public:
    int maxValue(Node* root) {
        // Code here
        if(!root) return 0;
        while(root -> right != NULL){
            root = root -> right;
        }
        return root -> data;
    }
};