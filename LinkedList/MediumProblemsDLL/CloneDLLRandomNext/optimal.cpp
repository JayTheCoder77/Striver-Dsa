/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
        void insertCopy(Node* head){
            Node* temp = head;
            while(temp != NULL){
                Node* copyNode = new Node(temp -> val);
                copyNode -> next = temp -> next;
                temp -> next = copyNode;
                temp = temp -> next -> next;
            }
        }
        void copyNodeRandom(Node* head){
             Node* temp = head;
                while (temp != NULL) {
                    if (temp->random) {
                        temp->next->random = temp->random->next;
                    }   
                temp = temp->next->next;
            }
        }
        Node* seperateLists(Node* head){
             Node* dummy = new Node(-1);
            Node* res = dummy;
            Node* temp = head;
    
            while (temp != NULL) {
                res->next = temp->next;
                res = res->next;
                temp->next = temp->next->next;
                temp = temp->next;
            }
    
            return dummy->next;
        }
        Node* copyRandomList(Node* head) {
            if(head == NULL) return NULL;
            insertCopy(head);
            copyNodeRandom(head);
            return seperateLists(head);
        }
    };

tc = o(3n)
sc = o(n)
