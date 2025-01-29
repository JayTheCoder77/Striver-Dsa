#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
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

void traverseLL(Node* head){
    Node* temp = head;
    while(temp){ // while(temp->next != nullptr)
        cout << temp->data << endl;
        temp = temp -> next;
    }
    cout << "Null" << endl;
}

int lengthLL(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp){ // while(temp->next != nullptr)
        len++;
        cout << temp->data << endl;
        temp = temp -> next;
    }
    cout << "Null" << endl;
    return len;
}

int searchInLinkedList(Node<int> *head, int k) {
    // Write your code here.
    Node<int>* temp = head;
    while(temp){ // while(temp->next != nullptr)
        if(temp->data == k){
            return 1;
        }
        temp = temp -> next;
    }
    return 0;
}

int main(){
    vector<int> arr = {2,3,4,7,8};
    Node* y = new Node(arr[0]);
    cout << y -> data << endl;
    Node* head = convertArrtoLL(arr);
    cout << head->data << endl;
    traverseLL(head);
    int len = lengthLL(head);
    cout << len << endl;
    return 0;
}


// tc = o(n) converting arr to LL
// tc = o(n) traverse LL and finding length of LL