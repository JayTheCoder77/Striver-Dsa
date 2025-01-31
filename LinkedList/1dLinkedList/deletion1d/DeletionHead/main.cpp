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

Node * deleteHead(Node *head) {
    // Write your code here.
    if(head == nullptr) return head;
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

int main(){
    vector<int> arr = {2,3,4,2};
    Node* head = convertArrtoLL(arr);
    head = deleteHead(head);
    cout << head -> data << endl;
    return 0;
}