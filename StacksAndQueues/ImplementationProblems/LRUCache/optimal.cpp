#include<bits/stdc++.h>
class Node{
    public :
    int data;
    int key;
    Node* next;
    Node* prev;
    Node(){
        data = 0;
        key = 0;
        next = NULL; 
        prev = NULL;
    }
    Node(int k,int val){
        key = k;
        data = val;
        next = NULL; 
        prev = NULL;
    }
    
};
class LRUCache
{
public:
    Node* head = new Node();
    Node* tail = new Node();
    int cap;
    map<int,Node*> mpp;
    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        mpp.clear();
        head -> next = tail;
        tail -> prev = head;
    }

    void insertAfterHead(Node* node){
        Node* currentAfterHead = head -> next;
        head -> next = node;
        node -> next = currentAfterHead;
        currentAfterHead -> prev = node;
        node -> prev = head;
    }
    void deleteNode(Node* node){
        if(!head) return;
        Node* prevN = node -> prev;
        Node* nextN = node -> next;
        prevN -> next = nextN;
        nextN -> prev = prevN;
    }

    int get(int key)
    {
        // Write your code here
        if(mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        // lru so we insert after head;
        deleteNode(node);
        insertAfterHead(node);
        return node -> data;
    }
    
    void put(int key, int value)
    {
        // Write your code here
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node -> data = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mpp.size() == cap){
            Node* node = tail -> prev;
            mpp.erase(node -> key);
            deleteNode(node);
            }
            Node* newNode = new Node(key , value);
            mpp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};

tc = o(1) for most operations a map might take o(logn) though
