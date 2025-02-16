RECURSION
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
int add(Node* head){
    Node* temp = head;
    if(temp == NULL) return 1;
    int carry = add(temp -> next);
    temp -> data += carry;
    if(temp -> data < 10) return 0;
    temp -> data = 0;
    return 1;
}
Node *addOne(Node *head)
{
    // Write Your Code Here.
    int carry = add(head);
    if(carry == 1){
        Node* newHead = new Node(1);
        newHead -> next = head;
        head = newHead;
        return head;
    }
    return head;
} 
tc = o(n)
sc = o(n) recursive stack space