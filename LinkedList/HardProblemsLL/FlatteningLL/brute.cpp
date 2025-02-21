#include <bits/stdc++.h>
/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* convertToVerticalLL(vector<int>arr){
	if(arr.size() == 0) return NULL;
	Node* head = new Node(arr[0]);
	Node* temp = head;
	for(int i = 1 ; i < arr.size() ; i++){
		Node* newNode = new Node(arr[i]);
		newNode -> next = NULL;
		temp -> child = newNode;
		temp = newNode;
	}
	return head;
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	Node* temp = head;
	Node* temp1 = NULL;
	vector<int> arr;
	while(temp != NULL){
		temp1 = temp;
		while(temp1 != NULL){
			arr.push_back(temp1->data);
			temp1 = temp1 -> child;
		}
		temp = temp -> next;
	}
	sort(arr.begin() , arr.end());
	Node* newHead = convertToVerticalLL(arr);
	return newHead;
}

x = n * m
tc = o(n * m) + o(xlogx) + o(n * m)             
sc = o(n * m)