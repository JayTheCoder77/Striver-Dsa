#include <bits/stdc++.h> 
/****************************************************************
    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*****************************************************************/

 bool getPath(BinaryTreeNode<int>* root, BinaryTreeNode<int>* x, vector<BinaryTreeNode<int>*> &path) {
        if (root == NULL) return false;
        path.push_back(root);
        if(root == x) return true;
        if (getPath(root->left, x, path) || getPath(root->right, x, path))
            return true;
        path.pop_back();
        return false;
    }
     vector<BinaryTreeNode<int>*> getPathtoNode(BinaryTreeNode<int>* A, BinaryTreeNode<int>* B) {
        vector<BinaryTreeNode<int> *> path;
        if (A == NULL) return path;
        getPath(A, B, path);
        return path;
    }
     BinaryTreeNode<int>* findLastCommon(vector<BinaryTreeNode<int>*> a,vector<BinaryTreeNode<int>*> b){
        BinaryTreeNode<int> *lastCommon=NULL;
        for(int i=0;i<min(a.size(),b.size());i++){
            if(a[i]==b[i]) lastCommon=a[i];
        }
        return lastCommon;
    }
BinaryTreeNode<int>* findLCA(BinaryTreeNode<int>* root, BinaryTreeNode<int>* u, BinaryTreeNode<int>* v) {
    // Write your code here.
    vector<BinaryTreeNode<int>*> pathToP = getPathtoNode(root,u);
        vector<BinaryTreeNode<int>*> pathToQ = getPathtoNode(root,v);
        BinaryTreeNode<int>* LCA = findLastCommon(pathToP,pathToQ);
        return LCA;
}