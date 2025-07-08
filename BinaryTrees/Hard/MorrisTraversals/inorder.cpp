class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        // morris traversal inorder
        vector<int> inorder;
        Node* cur = root;
        while(cur != NULL){
            // 1st case
            if(cur -> left == NULL){
                inorder.push_back(cur -> data);
                cur = cur -> right;
            }
            // 2nd case
            else{
                Node* prev = cur -> left;
                while(prev -> right && prev -> right != cur){
                    prev = prev -> right;
                }
                if(!prev -> right){
                    prev -> right = cur;
                    cur = cur -> left;
                }
                else{
                    prev -> right = NULL;
                    inorder.push_back(cur -> data);
                    cur = cur -> right;
                }
            }
        }
        return inorder;
    }
};

tc = o(n)
sc = o(1)