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
    print(head);
    return 0;
}