same bfs logic as nodes at k distance from root

class Solution {
public:
    void markParents(TreeNode* root , unordered_map<TreeNode*,TreeNode*> &parents){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node -> left){
                parents[node -> left] = node;
                q.push(node-> left);
            }
            if(node -> right){
                parents[node -> right] = node;
                q.push(node-> right);
            }
        }
    }
    TreeNode* findStart(TreeNode* root, int start){
        // preorder dfs
        if(!root) return NULL;
        if(root -> val == start) return root;
        TreeNode* left = findStart(root -> left , start); 
        if(left) return left;
        return findStart(root -> right , start); 
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        // bfs level order traversal
        unordered_map<TreeNode*,TreeNode*> parents;
        markParents(root , parents);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        TreeNode* s = findStart(root , start);
        int minutes = 0;
        q.push(s);
        visited[s] = true;
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0 ; i < size ; i++){
            TreeNode* node = q.front(); q.pop();
            // left 
            if(node -> left && !visited[node->left]){
                
                q.push(node -> left);
                visited[node -> left] = true;
            }
            // right 
            if(node -> right && !visited[node->right]){
                
                q.push(node -> right);
                visited[node -> right] = true;
            }
            // parent
            if(parents[node] && !visited[parents[node]]){
                
                q.push(parents[node]);
                visited[parents[node]] = true;
            }
            }
            if(!q.empty()) minutes += 1;
        }
        return minutes;
    }
};