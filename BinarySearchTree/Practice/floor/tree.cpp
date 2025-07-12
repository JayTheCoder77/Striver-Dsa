class Solution {

  public:
    int floor(Node* node, int x) {
        // Code here
    int floor1 = -1;
    while(node != NULL){
        
        if(node -> data == x) return x;
        if(node -> data > x) node = node -> left;
        else {
            floor1 = node -> data;
            node = node -> right;
        }
    }
    return floor1;
}
};