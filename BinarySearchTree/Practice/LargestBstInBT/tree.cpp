class NodeData {
public:
    int maxNode, minNode, maxSize;

    NodeData(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
// Return the size of the largest sub-tree which is also a BST'
// brute - pass evey node to dataidate a bst function
// optimal - postorder
class Solution {
  public:
    NodeData largestBSTSubtreeHelper(Node* root) {
        // An empty tree is a BST of size 0
        if (!root) return NodeData(INT_MAX, INT_MIN, 0);

        // Recursively get values from left and right subtrees
        NodeData left = largestBSTSubtreeHelper(root->left);
        NodeData right = largestBSTSubtreeHelper(root->right);

        // If current node is greater than max in left
        // and less than min in right, it's a valid BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            int newMin = min(root->data, left.minNode);
            int newMax = max(root->data, right.maxNode);
            int newSize = left.maxSize + right.maxSize + 1;
            return NodeData(newMin, newMax, newSize);
        }

        // Otherwise, not a BST, return size of largest BST found so far
        return NodeData(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    int largestBst(Node *root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};