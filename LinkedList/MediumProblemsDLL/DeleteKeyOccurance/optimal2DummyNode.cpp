/**
 * Definition of doubly linked list:
 *
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
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

 Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node* temp = head;
    Node* dummy = new Node(-1);
    Node* current = dummy;
    while(temp != NULL){
        if(temp -> data != k){
            current -> next = temp;
            temp -> prev = current;
            current = current -> next;
        }
        temp = temp -> next;
    }
    current -> next = NULL;
    return dummy -> next;
}

tc = o(n)
sc = o(1)
