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

Node *findMiddle(Node *head) {
    // Write your code here
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp -> next;
    }
    temp = head;
     int middleNode = (cnt / 2) + 1;
     while(temp != NULL){
         middleNode--;
         if(middleNode == 0) break;
         temp = temp -> next;
     }
     return temp;
}

tc = o(n) + o(n/2)
sc = o(1)