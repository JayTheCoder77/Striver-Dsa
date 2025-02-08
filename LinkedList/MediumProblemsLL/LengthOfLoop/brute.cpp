#include <bits/stdc++.h>
/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {
    // Write your code here
    Node* temp = head;
    map<Node*,int>mpp;
    int timer = 1;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()) return timer - mpp[temp];
        mpp[temp] = timer;
        timer++;
        temp = temp -> next;
    }
    return 0;
}

tc = o(n * 2logn)
sc = o(n)