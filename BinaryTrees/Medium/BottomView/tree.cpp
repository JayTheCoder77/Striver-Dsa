/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        // vertical line level order bfs traversal
        vector<int> ans;
        if (!root)
            return ans;
        map<int, int> lines;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node *x = it.first;
            int y = it.second;
            lines[y] = x->data;
            if (x->left)
                q.push({x->left, y - 1});
            if (x->right)
                q.push({x->right, y + 1});
        }
        for (auto p : lines)
            ans.push_back(p.second);
        return ans;
    }
};