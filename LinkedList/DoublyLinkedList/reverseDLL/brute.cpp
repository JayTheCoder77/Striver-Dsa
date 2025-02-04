#include <bits/stdc++.h>
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
    Node* temp = head;
    stack<int> s;
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