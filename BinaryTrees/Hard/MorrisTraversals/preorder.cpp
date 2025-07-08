class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> preorder;
        Node* cur = root;
        while(cur != NULL){
            // 1st case
            if(cur -> left == NULL){
                preorder.push_back(cur -> data);
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
                    preorder.push_back(cur -> data);
                    cur = cur -> left;
                }
                else{
                    prev -> right = NULL;
                    cur = cur -> right;
                }
            }
        }
        return preorder;
    }
};
tc = o(n) + o(n) 
sc = o(1)