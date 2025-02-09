/****************************************************************
Following is the Linked list node structure already written

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/

Node* oddEvenList(Node* head)
{
	// Write your code here.
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    vector <int> arr;
    // odd traversal - 1st index is considered odd
    while(temp != NULL && temp -> next != NULL){
        arr.push_back(temp->data);
        temp = temp -> next -> next;
    }
    if(temp) arr.push_back(temp -> data);
    temp = head -> next;
    // even traversal - 2nd index is considered even
    while(temp != NULL && temp -> next != NULL){
        arr.push_back(temp->data);
        temp = temp -> next -> next;
    }
    if(temp) arr.push_back(temp -> data);
    temp = head;
    int i = 0;
    // re traversal
    while(temp != NULL){
        temp -> data = arr[i++];
        temp = temp -> next;
    }
    return head;
}

tc = o(n/2) + o(n/2) + o(n) odd + even + full = o(2n)
sc = o(n)