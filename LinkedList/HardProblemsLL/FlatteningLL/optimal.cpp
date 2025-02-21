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
Node* merge(Node* head1 , Node* head2){
	// tc of merge func = o(n1 + n2)
	Node* dummy = new Node(-1);
	Node* res = dummy;
	Node* t1 = head1;
	Node* t2 = head2;
	while(t1 != NULL && t2 != NULL){
		if(t1 -> data < t2 -> data){
			res -> child = t1;
			res = res -> child;
			t1 = t1 -> child;
		}
		else{
			res -> child = t2;
			res = res -> child;
			t2 = t2 -> child;
		}
		res -> next = NULL;
	}
	if(t1){
		res -> child = t1;
	}
	if(t2){
		res -> child = t2;
	}
	return dummy -> child;
} 
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head == NULL || head -> next == NULL) return head;
	Node* mergedHead = flattenLinkedList(head->next);
	return merge(head,mergedHead);
}
tc = o(n * (n1 + n2))
sc = o(n) recursive stack space