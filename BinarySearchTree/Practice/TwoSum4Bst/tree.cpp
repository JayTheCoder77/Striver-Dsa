/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> s;
    bool reverse = false;
    // reverse = false = next 
    // else before
    public:
    BSTIterator(TreeNode* root , bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = s.top();
        s.pop();
        if(!reverse) pushAll(node -> right);
        else pushAll(node -> left);
        return node -> val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
    private :
        void pushAll(TreeNode* node){
            for(; node != NULL ;){
                s.push(node);
                if(reverse) node = node -> right;
                else node = node -> left;
            }
        }
};
class Solution {
public:
    // brute - inorder - sorted => normal 2 sum problem
    // tc = o(n) + o(n)
    // sc = o(n)



    // optimal - bst iterator - next and before 
    // as next will give next element in inorder ascending sorted order
    // vice versa before will give element in inorder descending sorted order
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        // next
        BSTIterator l (root , false);
        // before
        BSTIterator r (root , true);

        int i = l.next();
        int j = r.next(); // basically before
        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};