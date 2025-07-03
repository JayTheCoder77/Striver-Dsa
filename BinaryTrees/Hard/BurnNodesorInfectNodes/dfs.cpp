class Solution {
  public:
  void markParents(Node* root , unordered_map<Node*,Node*> &parents){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node -> left){
                parents[node -> left] = node;
                q.push(node-> left);
            }
            if(node -> right){
                parents[node -> right] = node;
                q.push(node-> right);
            }
        }
    }
    Node* findStart(Node* root, int start){
        // preorder dfs
        if(!root) return NULL;
        if(root -> data == start) return root;
        Node* left = findStart(root -> left , start); 
        if(left) return left;
        return findStart(root -> right , start); 
    }
    int height(Node* start , unordered_map<Node*,Node*>&par ,  unordered_map<Node*, bool>&vis){
        // dfs
        if(!start) return 0;
        vis[start] = true;
        int lh = INT_MIN;
        int rh = INT_MIN;
        int ph = INT_MIN;
        
        if(!vis[start -> left]){
            lh = height(start -> left , par , vis);
        }
        if(!vis[start -> right]){
            rh = height(start -> right , par , vis);
        }
        if(!vis[par[start]]){
            ph = height(par[start] , par , vis);
        }
        return max(lh , max(rh , ph)) + 1;
    }
    int minTime(Node* root, int target) {
        // code here
        // dfs
        unordered_map<Node*,Node*> parents;
        unordered_map<Node*,bool> visited;
        markParents(root , parents);
        Node* start = findStart(root , target);
        int h = height(start , parents , visited);
        return h - 1;
    }
};