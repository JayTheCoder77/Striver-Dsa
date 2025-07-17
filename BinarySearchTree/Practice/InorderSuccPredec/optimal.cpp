class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        // brute - inorder - use binary search / linear search to find value greater/smaller than key
        // brute - tc = o(n)+  sc = o(n)
        // better - morris or other traversal - find value just bigger than key
        // optimal
        vector<Node*> ans(2, NULL);
        Node* successor = NULL;
        Node* predecessor  = NULL;
        
        // predecessor
        Node* cur = root;
        while(cur){
            if(cur -> data < key){
                predecessor = cur;
                cur = cur -> right;
            }
            else{
                cur = cur -> left;
            }
        }
        // successor
        cur = root;
        while(cur){
            if(cur -> data > key){
                successor = cur;
                cur = cur -> left;
            }
            else{
                cur = cur -> right;
            }
        }
        ans[0] = predecessor;
        ans[1] = successor;
        return ans;
    }
};

tc = o(h)
sc = o(1)
