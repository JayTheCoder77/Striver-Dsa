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

Node * insertPos(Node *head , int val , int k) {
    // Write your code here.
    if(head == nullptr){
        if(k == 1) return new Node(val);
        else return head;
    }
    if(k == 1) return new Node(val,head);
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        if(count == k - 1){
            Node* toInsert = new Node(val , temp -> next);
            temp -> next = toInsert;
            break;
        }
        temp = temp -> next;
    }
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
    head = insertPos(head,100,2);
    traverseLL(head);
    return 0;
}

tc = o(n) if k = last pos