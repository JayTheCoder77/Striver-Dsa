#include<bits/stdc++.h>
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

bool isPalindrome(Node *head)
{
    // write your code here
    stack<int>st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp -> data);
        temp = temp -> next;
    }
    temp = head;
    while(temp != NULL){
        int value = st.top();
        if(temp -> data != value) return false;
        st.pop();
        temp = temp -> next;
    }
    return true;
}

tc = o(n) + o(n)
sc = o(n)