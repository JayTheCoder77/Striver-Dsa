void inorder(TreeNode* root , vector<int>& ans){
        if(!root) return;
        inorder(root -> left , ans); 
        ans.push_back(root -> data);
        inorder(root -> right , ans); 
    }
    
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> a;
    vector<int> b;
    inorder(root1 , a);
    inorder(root2 , b);
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) res.push_back(a[i++]);
        else res.push_back(b[j++]);
    }
    while (i < a.size()) res.push_back(a[i++]);
    while (j < b.size()) res.push_back(b[j++]);
    return res;
}   