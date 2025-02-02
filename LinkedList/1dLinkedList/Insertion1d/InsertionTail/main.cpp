#include <bits/stdc++.h>
using namespace std;
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

Node* convertArrtoLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; // or mover = mover->next
    }
    return head;
    }

Node * insertTail(Node *head , int val) {
    // Write your code here.
    if(head == nullptr) return new Node(val , head);
    Node* temp = head;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    Node* toinsert = new Node(val);
    temp -> next = toinsert;
    return head;
}

void traverseLL(Node* head){
    Node* temp = head;
    while(temp){ // while(temp->next != nullptr)
        cout << temp->data << endl;
        temp = temp -> next;
    }
    cout << "Null" << endl;
}

int main(){
    vector<int> arr = {2,3,4,2};
    Node* head = convertArrtoLL(arr);
    head = insertTail(head,100);
    traverseLL(head);
    return 0;
}