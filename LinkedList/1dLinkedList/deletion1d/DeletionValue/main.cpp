// deletion of value


Node* removeVal(Node* head, int val){
    if(head == nullptr) return head;
    if(head -> data == val){
            Node* temp = head;
            head = head -> next;
            delete temp;
            return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        if(temp -> data == val){
            prev -> next = prev -> next -> next;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
        delete temp;
        return head;
}

// leetcode - remove all the elements with same value


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    if(head == nullptr) return head;
    while(head != nullptr && head -> val == val){
            ListNode* temp = head;
            head = head -> next;
            delete temp;
    }
    ListNode* current = head;
    while(current != nullptr && current -> next != nullptr){
            if(current->next->val == val){
                ListNode* todelete = current -> next;
                current->next = current -> next -> next;
                delete todelete;
            }
            else{
                current = current -> next;
            }
        }
    return head;
    }
 
};