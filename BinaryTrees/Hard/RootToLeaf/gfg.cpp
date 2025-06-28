class Solution {
  public:
    void dfs(Node* node , vector<vector<int>> &r , vector<int> &s){
        if(!node) return;
        s.push_back(node ->data);
        if(!node -> left && !node -> right) r.push_back(s);
        else{
            dfs(node-> left,r,s);
            dfs(node-> right,r,s);
        }
        s.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> result;
        vector<int> path;
        if(!root) return result;
        dfs(root , result , path);
        return result;
    }
};