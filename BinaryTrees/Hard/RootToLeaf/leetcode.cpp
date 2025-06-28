class Solution {
public:
    void dfs(TreeNode* node , vector<string> &r , string s){
        if(!node) return;
        if(!s.empty()) s += "->";
        s += to_string(node -> val);
        if(!node -> left && !node -> right) r.push_back(s);
        else{
            dfs(node -> left , r , s);
            dfs(node -> right , r , s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root) return result;
        dfs(root , result , "");
        return result;
    }
};