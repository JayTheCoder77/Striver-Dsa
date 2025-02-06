#include <bits/stdc++.h>
/****************************************************************

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
        

*****************************************************************/

Node* reverseLinkedList(Node *head)
{
    // Write your code here
    stack<int> s;
    Node* temp = head;
    while(temp != NULL){
        s.push(temp -> data);
        temp = temp -> next;
    }
    temp = head;
    while(temp != NULL){
    temp -> data = s.top();
    s.pop();
    temp = temp -> next;
    }
    return head;
}


tc = o(n) + o(n) = o(2n)
sc = o(n)