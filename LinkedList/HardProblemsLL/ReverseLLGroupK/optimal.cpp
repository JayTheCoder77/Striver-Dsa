/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
void reverse(Node* head){
    Node* temp = head;
    Node* front = NULL;
    Node* back = NULL;
    while(temp != NULL){
        front = temp -> next;
        temp -> next = back;
        back = temp;
        temp = front;
    }
}
Node* findKthNode(Node* head , int k){
    k -= 1;
    Node* temp = head;
    while(temp != NULL && k > 0){
        k--;
        temp = temp -> next;
    }
    return temp;
}
Node* kReverse(Node* head, int k) {
    // Write your code here.
    Node* temp = head;
    Node* prevNode = NULL;
    while(temp != NULL){
        Node* kthNode = findKthNode(temp,k);
        if(kthNode == NULL){
            if(prevNode) prevNode -> next = temp;
            break;
        }
        Node* nextNode = kthNode -> next;
        kthNode -> next = NULL;
        reverse(temp);
        if(temp == head) head = kthNode;
        else prevNode -> next = kthNode;
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}
tc = o(n) + o(n)
sc = o(1) 