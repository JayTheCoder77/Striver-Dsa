void dfs(TreeNode<int> *root , int &cnt){
    if(!root) return;
    cnt++;
    dfs(root -> left,cnt);
    dfs(root -> right,cnt);
}
int countNodes(TreeNode<int> *root)
{
    //    Write your code here.
    int count = 0;
    dfs(root , count);
    return count;
}


any dfs sequence pre in or post

tc = o(n)
auxillary sc = o(h) worst sc = o(logn)