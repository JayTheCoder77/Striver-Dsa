class Solution {
public:
    unordered_map <int , TreeNode*> valToNode;
    unordered_map<int, int> inDeg;
    set<int> allVals;

    void collect(TreeNode* node){
        // check if the root is leaf node of any tree or no 
        // if a root is not a leaf noode of any other tree we start merging from   this tree
        if(!node) return;
        allVals.insert(node -> val);
        if(node-> left){
            inDeg[node -> left -> val]++;
            collect(node -> left);
        }
        if(node-> right){
            inDeg[node -> right -> val]++;
            collect(node -> right);
        }
    }

    TreeNode* merge(TreeNode* node){
        if(!node) return NULL;

        if(node -> left && valToNode.count(node -> left -> val)){
            node -> left = valToNode[node -> left -> val];
            valToNode.erase(node -> left -> val);
            merge(node -> left);
        }
        if(node -> right && valToNode.count(node -> right -> val)){
            node -> right = valToNode[node -> right -> val];
            valToNode.erase(node -> right -> val);
            merge(node -> right);
        }
        return node;
    }
    // validate bst
    bool isValid(TreeNode* root , int minVal , int maxVal){
        if(root == NULL) return true;
        if(root -> val >= maxVal || root -> val <= minVal) return false;
        return isValid(root -> left , minVal , root -> val) && isValid(root -> right , root -> val , maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root , INT_MIN , INT_MAX);
    }
    // ***********
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        // storing values
        for(auto tree : trees){
            valToNode[tree->val] = tree;
            collect(tree);
        }
        TreeNode* root = NULL;

        // finding the root which isnt a leaf
        for(auto tree : trees){
            if(inDeg[tree->val] == 0){
                if(root) return NULL;
                root = tree;
            }
        }
        if(!root) return NULL;

        // merge
        valToNode.erase(root -> val);
        root = merge(root);
        if(!valToNode.empty()) return NULL;
        return isValidBST(root) ? root : NULL;
    }
};