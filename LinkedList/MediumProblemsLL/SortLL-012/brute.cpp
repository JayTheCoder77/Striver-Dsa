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

Node* sortList(Node *head){
    // Write your code here.
    int count0 = 0 ,count1 = 0 , count2 = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0) count0++;
        else if(temp -> data == 1) count1++;
        else count2++;
        temp = temp -> next;
    }
    temp = head;
    while(temp != NULL){
        if(count0){
            temp -> data = 0;
            count0--;
        }
        else if(count1){
            temp -> data = 1;
            count1--;
        }
        else if(count2){
            temp -> data = 2;
            count2--;
        }
        temp = temp -> next;
    }
    return head;
}

tc = o(n) + o(n)
sc = o(1)