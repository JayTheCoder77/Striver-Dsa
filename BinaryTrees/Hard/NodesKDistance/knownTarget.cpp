// leetcode

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root , unordered_map<TreeNode* , TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node -> left){
                parent[node -> left] = node;
                q.push(node -> left);
            }
            if(node -> right){
                parent[node -> right] = node;
                q.push(node -> right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // bfs
        vector<int> ans;
        if(!root) return ans;
        unordered_map<TreeNode* , TreeNode*> parent;
        markParents(root , parent);
        
        unordered_map<TreeNode* , bool > visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int level = 0;
        // 1. parent marking done 2. greedy bfs traversal to up , left , right
        while(!q.empty()){
            int size = q.size();
            if(level++ == k) break;
            for(int i = 0 ; i < size ; i++){
                TreeNode* curr = q.front(); q.pop();
                // check left
                if(curr -> left && !visited[curr -> left]){
                    q.push(curr -> left);
                    visited[curr -> left] = true;
                }
                // right
                if(curr -> right && !visited[curr -> right]){
                    q.push(curr -> right);
                    visited[curr -> right] = true;
                }
                // parent
                if(parent[curr] && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            ans.push_back(node -> val);
        }
        return ans;
    }
};