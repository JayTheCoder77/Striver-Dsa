struct Node
{
    Node *left;
    Node *right;
    int data;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

preorder = root -> left -> right

void preorder(Node *node){
    if(node == NULL) return;
    cout << node -> data << " ";
    preorder(node -> left);
    preorder(node -> right); 
}

tc = o(n)
sc = o(height of tree) -> o(n)


// leetcode
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        ans.push_back(root -> val);
        vector<int> left = preorderTraversal(root -> left);
        ans.insert(ans.end(), left.begin(), left.end());
        vector<int> right = preorderTraversal(root -> right);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }
};