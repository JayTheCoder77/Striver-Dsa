/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

 vector<pair<int, int>> findPairs(Node* head, int k)
 {
     // Write your code here.
     Node* left = head;
     Node* right = head;
     vector<pair<int,int>> ans;
     while(right -> next != NULL){
         right = right -> next;
     }
     while(left -> data < right -> data){
     if(left -> data + right -> data > k) right = right -> prev;
     else if(left -> data + right -> data < k) left = left -> next;
     else{
         ans.push_back({left->data,right->data});
         right = right -> prev;
         left = left -> next;
     }
 }
     return ans;
 }

 tc = o(n) + o(n)
 sc = o(1) we use space only to return ans 