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
Node* findNthNode(Node* head , int len){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
         count++;
         if(count == len) break;
         temp = temp -> next;
    }
    return temp;
}
Node *rotate(Node *head, int k) {
    // Write your code here.
    Node* tail = head;
    int len = 1;
    while(tail -> next != NULL){
         len++;
         tail = tail -> next;
    }
    if(k % len == 0) return head;
    k = k % len;
    tail -> next = head;
    Node* newLastNode = findNthNode(head,len-k);
    head = newLastNode -> next;
    newLastNode -> next = NULL;
    return head;
}

tc = o(2n)
sc = o(1)