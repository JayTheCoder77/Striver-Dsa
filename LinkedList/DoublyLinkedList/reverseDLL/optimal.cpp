/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/
Node* reverseDLL(Node* head)
{   
    // Write your code here
    if(head == NULL || head -> next == NULL) return head;   
    Node* current = head;
    Node* back = NULL;
    while(current != NULL){
        back = current -> prev;
        current -> prev = current -> next;
        current -> next = back;
        current = current -> prev;
    }
    return back -> prev;
}

tc = o(n)
sc = o(1)