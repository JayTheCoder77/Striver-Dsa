#include <bits/stdc++.h>
using namespace std;


 // Definition for doubly-linked list.
class Node
{
public:
   int data;
   Node *next, *prev;
   Node() : data(0), next(nullptr), prev(nullptr) {}
   Node(int x) : data(x), next(nullptr), prev(nullptr) {}
   Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};

Node* insertBeforeHead(Node* head , int val){
    if(head == NULL) return new Node(val,nullptr,nullptr);
    Node* newHead = new Node(val,head,nullptr);
    head -> prev = newHead;
    return newHead;
}

Node* insertAfterHead(Node* head , int val){
    if(head == NULL) return new Node(val);
    Node* newAfterHead = new Node(val,head->next,head);
    if(head -> next != NULL){
        head -> next -> prev = newAfterHead;
    }
    head -> next = newAfterHead;
    return head;
}

Node* insertBeforeTail(Node* head , int val){
    if(head == NULL) return new Node(val);
    Node* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    Node* back = tail -> prev;
    Node* newNode = new Node(val,tail,back);
    back -> next = newNode;
    tail -> prev = newNode;
    return head;
}

Node* insertAfterTail(Node* head , int val){
    if(head == NULL) return new Node(val);
    Node* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    Node* newNode = new Node(val,nullptr,tail);
    tail -> next = newNode;
    return head;
}

Node* insertAtPos(Node* head , int val , int pos){
    if(head == NULL) return new Node(val);
    if(pos == 1) return insertBeforeHead(head,val);
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == pos) break;
        temp = temp -> next;
    }
    Node* back = temp -> prev;
    Node* newNode = new Node(val,temp,back);
    back -> next = newNode;
    temp -> prev = newNode;
    return head;
}

void insertBeforeNode(Node* node,int val){
    Node* back = node -> prev;
    Node* newNode = new Node(val,node,back);
    back -> next = newNode;
    node -> prev = newNode;
}

Node* constructDLL(vector<int>& arr) {
    // Write your code here
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1 ; i < n ; i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;    // prev = prev -> next; same as this line
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main(){
    vector<int> arr = {12,5,8,7};
    Node* head = constructDLL(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKth(head,2);
    // deleteNode(head -> next);
    // head = insertBeforeHead(head,10);
    // head = insertAfterHead(head,13);
    // head = insertBeforeTail(head,13);
    // head = insertAfterTail(head,13);
    // head = insertAtPos(head,13,2);
    insertBeforeNode(head->next->next,13);
    print(head);
    return 0;
}