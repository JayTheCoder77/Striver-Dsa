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
    Node* slow = head;
    Node* fast = head;
    for(int i = 0 ; i < K ; i++) fast = fast -> next;
    if(fast == NULL) return head -> next;
    while(fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next;
    }
    Node* deleteNode = slow -> next;
    slow -> next = slow -> next -> next;
    free(deleteNode);
    return head;
}

tc = o(n) as fast pointer moved till end of LL
sc = o(1)