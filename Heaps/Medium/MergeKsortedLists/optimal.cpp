[Naive Approach  1]  Merge One by One
[Naive Approach  2] Repeatedly Select Min of All Remaining
[Expected Approach  1]  Using Min Heap (Works better for unequal sized lists)
[Expected Approach  2]  Using Divide and Conquer (Works better for equal sized lists)
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
    // Custom comparator for the min-heap
    struct CompareNodes {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // For min-heap, we need "greater than"
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , CompareNodes> pq;
        // min heap optimal
        for(int i = 0 ; i < lists.size() ; i++){
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }
        // start merging
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(!pq.empty()){
            ListNode* current = pq.top();
            pq.pop();

            temp -> next = current;
            temp = temp -> next;
            if(current -> next != NULL){
                pq.push(current -> next);
            }
        }
        ListNode* result = dummyNode->next;
        delete dummyNode; // Avoid memory leak
        return result;
    }
};

m = k*n
tc = o(klogk) + o(m * 3logk)
sc = o(k)
