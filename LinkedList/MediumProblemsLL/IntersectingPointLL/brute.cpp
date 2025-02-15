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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    map<Node*,int> mpp;
    Node* temp = firstHead;
    while(temp != NULL){
        mpp[temp] = 1;
        temp = temp -> next;
    }
    temp = secondHead;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()) return temp;
        temp = temp -> next;
    }
    return NULL;
}

tc = o(n1 logn1) + o(n2 * logn2)
sc = o(n1) or o(n2) depends on which LL we store