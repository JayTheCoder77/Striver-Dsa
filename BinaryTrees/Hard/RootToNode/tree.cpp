bool preorder(TreeNode<int> *node, int x , vector<int> &a){
	if(!node) return false;
	a.push_back(node -> data);
	if(node -> data == x) return true;
	if(preorder(node -> left , x , a) || preorder(node -> right , x , a)) return true;
	a.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	if(!root) return ans;
	preorder(root , x , ans);
	return ans;
}