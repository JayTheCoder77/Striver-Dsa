/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    if(count == K){
        Node* newHead = head -> next;
        free(head);
        return newHead;
    }
    int result = count - K;
    temp = head;
    while(temp != NULL){
        result--;
        if(result == 0) break;
        temp = temp -> next;
    }
    Node* todelete = temp -> next;
    temp -> next = temp -> next -> next;
    free(todelete);
    return head;
}
tc = o(n) + o(n - k) n is length of LL  
sc = o(1)