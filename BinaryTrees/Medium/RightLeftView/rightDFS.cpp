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
    void dfs(TreeNode* node , int level ,vector<int> &ds){
        if(!node) return;
        if(level == ds.size()) ds.push_back(node -> val);
        if(node -> right) dfs(node-> right , level + 1, ds);
        if(node -> left) dfs(node-> left , level + 1, ds);
    }
    vector<int> rightSideView(TreeNode* root) {
        // last node of every level - dfs (not bfs as at some point the queue will store a lot of nodes)
        // modified dfs - ROOT RIGHT LEFT
        vector<int> ans;
        if(!root) return ans;
        dfs(root , 0 , ans);
        return ans;
    }
};

tc = o(n)
sc = o(height)