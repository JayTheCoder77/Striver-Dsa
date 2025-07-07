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
class Solution {
public:
    TreeNode* build(vector<int>& inorder, int inS , int inE ,vector<int>& postorder , int postS , int postE , unordered_map<int,int> &mpp){
        if(postS > postE || inS > inE) return NULL;
        TreeNode* root = new TreeNode(postorder[postE]);
        int inRoot = mpp[root -> val];
        int numsLeft = inRoot - inS;
        root -> left = build(inorder , inS , inRoot - 1 , postorder , postS , postS + numsLeft - 1 ,mpp);
        root -> right = build(inorder , inRoot + 1  , inE , postorder , postS + numsLeft , postE - 1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < inorder.size() ; i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = build(inorder , 0 , inorder.size() - 1 , postorder , 0 , postorder.size() - 1 , mpp);
        return root;
    }
};

tc = o(n logn)
sc = o(n)