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

Node* deleteHead(Node* head){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    Node* back = head;
    head = head -> next;
    
    head -> prev = nullptr;
    back -> next = nullptr;
    delete back;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    Node* back = tail -> prev;
    back -> next = nullptr;
    tail -> prev = nullptr;
    delete tail;
    return head;
}

Node* deleteKth(Node* head , int k){
    if(head == NULL){
        return NULL;
    }
    int cnt = 0;
    Node* knode = head;
    while(knode != NULL){
        cnt++;
        if(cnt == k) break;
        knode = knode -> next;
    }
    Node* back = knode -> prev;
    Node* front = knode -> next;

    if(back == NULL && front == NULL){
        return NULL;
    }
    else if(back == NULL){
        return deleteHead(head);
    }
    else if(front == NULL){
        return deleteTail(head);
    }

    back -> next = front;
    front -> prev = back;
    delete knode;
    return head;
}

void deleteNode(Node* node){
    Node* front = node -> next;
    Node* back  = node -> prev;

    if(front == NULL){
        back -> next = nullptr;
        node -> prev = nullptr;
        delete node;
        return;
    }
    back -> next = front;
    front -> prev = back;
    node -> next = node -> prev = nullptr;
    delete node;
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
    deleteNode(head -> next);
    print(head);
    return 0;
}