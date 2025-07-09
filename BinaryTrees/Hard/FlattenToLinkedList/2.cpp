void flattenBinaryTree(TreeNode<int>* root)
{
    // Write your code here.
    stack<TreeNode<int>*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode<int>* cur = st.top();
        st.pop();
        if(cur -> right) st.push(cur -> right);
        if(cur -> left) st.push(cur -> left);
        if(!st.empty()) cur -> right = st.top();
        cur -> left = NULL;
    }
}

tc = o(n)
sc = o(n)