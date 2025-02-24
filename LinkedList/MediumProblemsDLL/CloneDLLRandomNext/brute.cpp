#include <bits/stdc++.h>
/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *random;
 *		Node() : data(0), next(nullptr), random(nullptr){};
 *		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 *		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
 * };
 */

Node *cloneLL(Node *head){
	// Write your code here
	map<Node*,Node*> mpp;
	Node* temp = head;
	while(temp != NULL){
		Node* newNode = new Node(temp -> data);
		mpp[temp] = newNode;
		temp = temp -> next;
	}
	temp = head;
	while(temp != NULL){
		Node* copyNode = mpp[temp];
		copyNode -> next = temp -> next;
		copyNode -> random = temp -> random;
		temp = temp -> next;
	}
	return mpp[head];
}

tc = o(2nlogn) logn hash map
sc = o(n) + o(n) for returning cloned ll