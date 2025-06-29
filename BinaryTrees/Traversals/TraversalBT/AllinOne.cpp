/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans(3);
    if(root == NULL) return ans;
    stack<pair<TreeNode*,int>> s;
    s.push({root,1});
    while(!s.empty()){
        auto it = s.top();
        s.pop();
        if(it.second == 1){
            ans[1].push_back(it.first->data);
            it.second++;
            s.push(it);

            if(it.first->left){
                s.push({it.first->left , 1});
            }
        }
        else if(it.second == 2){
            ans[0].push_back(it.first->data);
            it.second++;
            s.push(it);

            if(it.first->right) s.push({it.first->right , 1});
        }
        else ans[2].push_back(it.first->data);
    }
    return ans;
}