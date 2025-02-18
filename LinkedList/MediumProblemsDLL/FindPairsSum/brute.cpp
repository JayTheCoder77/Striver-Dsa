#include <bits/stdc++.h>
/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    Node* temp1 = head;
    vector <pair<int,int>> ans;
    while(temp1 != NULL){
        Node* temp2 = temp1 -> next;
        while(temp2 != NULL && temp1 -> data + temp2 -> data <= k){
           if(temp1 -> data + temp2 -> data == k) ans.push_back({temp1 -> data , temp2 -> data});
            temp2 = temp2 -> next;
        }
    temp1 = temp1 -> next;
    }
    return ans;
}
tc = o(n2)
sc = o(1)