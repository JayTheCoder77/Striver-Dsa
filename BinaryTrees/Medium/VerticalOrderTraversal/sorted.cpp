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

 nodes map

{
  -1: {1: {9}},
   0: {0: {3}, 2: {15}},
   1: {1: {20}},
   2: {2: {7}}
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // level order traversal bfs
        map<int , map<int , multiset<int> > > nodes; 
        queue<pair < TreeNode* , pair <int , int > > > todo; // top down
        // node , vertical , level
        todo.push({root , {0 , 0}});
        // bfs
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first , y = p.second.second;
            nodes[x][y].insert(node -> val); 
            if(node -> left) todo.push({node -> left , {x -1  , y + 1}});
            if(node -> right) todo.push({node -> right , {x + 1  , y + 1}});
        }
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

tc = o(nlogn) -due to multiset logn
sc = o(n)






