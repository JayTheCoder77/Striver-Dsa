/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    // recurisve dfs cannot be used 
    vector<int> topView(Node *root) {
        // code here
        // bfs level order traversal
        // vertical lines 
        vector<int> ans;
        if(!root) return ans;
        map<int,int> lines;
        queue<pair<Node* , int>> q;
        q.push({root , 0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* x = it.first;
            int y = it.second;
            if(lines.find(y) == lines.end()) lines[y] = x -> data;
            if(x -> left) q.push({x -> left , y - 1});
            if(x -> right) q.push({x -> right , y + 1});
        }
        for(auto it : lines) ans.push_back(it.second);
        return ans;
    }
};

