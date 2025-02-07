// find starting point of the loop loop in linked list II

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

Node *firstNode(Node *head)
{
    //    Write your code here.
    map<Node* , int> mpp;
    Node* temp = head;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()) return temp;
        mpp[temp] += 1;
        temp = temp -> next;
    }
    return NULL;
}

tc = o(n * 2logn)
sc = o(n)

