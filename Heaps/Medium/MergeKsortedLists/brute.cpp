#include<bits/stdc++.h>
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
Node* convertToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; // or mover = mover->next
    }
    return head;
}
Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    vector<int> res;
    for(int i = 0 ; i < listArray.size() ; i++){
        Node* temp = listArray[i];
        while(temp != NULL){
            res.push_back(temp -> data);
            temp = temp -> next;
        }
    }
    sort(res.begin() , res.end());
    Node* head = convertToLL(res);
    return head;
}

m = n * k
tc = o(n * k) + o(m log m) + o(m)
sc = o(m) + o(m)
