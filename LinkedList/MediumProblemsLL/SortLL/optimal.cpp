#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
// tortoise hare to find middle but slight edge case here we dont want second middle in case
// of even nodes we want exact middle 
Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head -> next;  // slight change so slow stops at first middle not the second middle 
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

// merge two lists

Node* mergeTwoLists(Node* first, Node* second)
{
    // Write your code here.
    
    Node* t1 = first;
    Node* t2 = second;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(t1 != NULL && t2 != NULL){
        if(t1 -> data < t2 -> data){
            temp -> next = t1;
            temp = t1;
            t1 = t1 -> next;
        }
        else{
            temp -> next = t2;
            temp = t2;
            t2 = t2 -> next;
        }
    }
    if(t1) temp -> next = t1;
    else temp -> next = t2;
    return dummyNode -> next;
}

Node *sortLL(Node *head)
{
    // Write your code here.
    // merge sort
    if(head == NULL || head -> next == NULL) return head;
    Node* middle = findMiddle(head);
    Node* leftHead = head;
    Node* rightHead = middle -> next;
    middle -> next = NULL;
    leftHead = sortLL(leftHead);
    rightHead = sortLL(rightHead);
    return mergeTwoLists(leftHead,rightHead);
}

// although merge sort used tc sc is diff as we are applying merge sort on LL
tc = o(logn * (n + n/2))
sc = o(1)
// sc = o(logn) recursive stack space