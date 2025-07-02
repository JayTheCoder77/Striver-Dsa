bool isParentSum(Node *root){
    // Write your code here.
    if (!root || (!root->left && !root->right)) {
        return true;
    }
    int left = root -> left ? root -> left -> data : 0;
    int right = root -> right ? root -> right -> data : 0;

    return (root -> data == left + right) && isParentSum(root -> left) && isParentSum(root -> right);
}


we only check if the property exists or not