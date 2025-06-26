#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void dfs(TreeNode<int>* node , int level ,vector<int> &ds){
        if(!node) return;
        if(level == ds.size()) ds.push_back(node -> data);
        if(node -> left) dfs(node-> left , level + 1, ds);
        if(node -> right) dfs(node-> right , level + 1, ds);
    }
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    // last node of every level - dfs (not bfs as at some point the queue will store a lot of nodes)
        // modified dfs - ROOT RIGHT LEFT
        vector<int> ans;
        if(!root) return ans;
        dfs(root , 0 , ans);
        return ans;
}