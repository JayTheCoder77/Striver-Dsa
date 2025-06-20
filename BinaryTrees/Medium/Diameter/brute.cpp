class Solution {
  public:
    int Ht(Node* node){
        if(node == NULL) return 0;
        int lh = Ht(node -> left);
        int rh = Ht(node -> right);
        return 1 + max(lh , rh);
    }
    int maxi = 0;
    int diameter(Node* node) {
        // Your code here
        if(node == NULL) return 0;
        int lh = Ht(node -> left);
        int rh = Ht(node -> right);
        maxi = max(maxi,lh + rh);
        diameter(node -> left);
        diameter(node -> right);
        return maxi;
    }
};

tc = o(n2)
sc = o()