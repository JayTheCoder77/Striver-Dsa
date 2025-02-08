/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/
int findLength(Node* slow,Node* fast){
    int count = 1;
    fast = fast -> next;
    while(fast != slow){
    fast = fast -> next;
    count++;
    }
    return count;
}
int lengthOfLoop(Node *head) {
    // Write your code here
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) return findLength(slow,fast);
    }
    return 0;
}

tc = o(n) + o(m) m is length of loop if loop exists
sc = o(1)