// gfg

class Solution {
  public:
    void markParents(Node* root, unordered_map<Node*, Node*>& parent) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    Node* findTarget(Node* root, int target) {
        if (!root) return nullptr;
        if (root->data == target) return root;
        Node* left = findTarget(root->left, target);
        if (left) return left;
        return findTarget(root->right, target);
    }

    vector<int> KDistanceNodes(Node* root, int target, int k) {
        vector<int> ans;
        if (!root) return ans;

        unordered_map<Node*, Node*> parent;
        markParents(root, parent);

        Node* targetNode = findTarget(root, target);
        if (!targetNode) return ans; // target not found

        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (level++ == k) break;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front(); q.pop();
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }

        while (!q.empty()) {
            ans.push_back(q.front()->data);
            q.pop();
        }

        sort(ans.begin(), ans.end()); // problem usually requires sorted output
        return ans;
    }
};