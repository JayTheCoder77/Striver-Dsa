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
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* front = NULL;
    Node* temp = head;
    while(temp != NULL){
        front = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
Node *addOne(Node *head)
{
    // Write Your Code Here.
    head = reverse(head);
    int carry = 1;
    Node* temp = head;
    while(temp != NULL){
        temp -> data += carry;
        if(temp -> data < 10){
            carry = 0;
            break;
        }
        else{
            temp -> data = 0;
            carry = 1;
        }
        temp = temp -> next;
    }
    head = reverse(head);
    if(carry == 1){
        Node* newHead = new Node(1);
        newHead -> next = head;
        head = newHead;
    }
    return head;
}
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
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* front = NULL;
    Node* temp = head;
    while(temp != NULL){
        front = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
Node *addOne(Node *head)
{
    // Write Your Code Here.
    head = reverse(head);
    int carry = 1;
    Node* temp = head;
    while(temp != NULL){
        temp -> data += carry;
        if(temp -> data < 10){
            carry = 0;
            break;
        }
        else{
            temp -> data = 0;
            carry = 1;
        }
        temp = temp -> next;
    }
    head = reverse(head);
    if(carry == 1){
        Node* newHead = new Node(1);
        newHead -> next = head;
        head = newHead;
    }
    return head;
}

tc = o(3n)
sc = o(1)