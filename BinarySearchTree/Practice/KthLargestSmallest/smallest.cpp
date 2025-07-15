class Solution {
public:
        // naive -> dfs -> vector sort -> kth largest / smallest
        // tc - o(n logn)   sc = o(n)


        // better
        // inorder of a bst is - always sorted
        // still is sc - o(n) for dfs vector


        // optimal - inorder morris 
        // keeping a count
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        int cnt = 0 , ans = 0;
        while(cur != NULL){
            // 1st case
            if(cur -> left == NULL){
                cnt++;
                if (cnt == k) ans = cur->val;
                cur = cur -> right;
            }
            // 2nd case
            else{
                TreeNode* prev = cur -> left;
                while(prev -> right && prev -> right != cur){
                    prev = prev -> right;
                }
                if(!prev -> right){
                    prev -> right = cur;
                    cur = cur -> left;
                }
                else{
                    prev -> right = NULL;
                    cnt++;
                    if(cnt == k) ans = cur -> val;
                    cur = cur -> right;
                }
            }
        }
        return ans;
    }
};