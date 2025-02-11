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

Node* deleteMiddle(Node* head){
    // Write your code here.
    if(head == NULL || head -> next == NULL) return NULL;
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    int mid = (count / 2);
    int res = mid - 1;
    temp = head;
    while(temp != NULL){
        if(res == 0) break;
        res--;
        temp = temp -> next;
    }
    Node* todelete = temp -> next;
    temp -> next = temp -> next -> next;
    free(todelete);
    return head;
}

tc = o(n) + o(n/2)
sc = o(1)