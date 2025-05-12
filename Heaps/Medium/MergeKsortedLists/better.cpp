/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    public:
      Node* merge2lists(Node* first , Node* second){
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

      Node* mergeKLists(vector<Node*>& arr) {
          // Your code here
          Node* head = arr[0];
          for(int i = 1 ; i < arr.size() ; i++){
          head = merge2lists(head,arr[i]);
          }
          return head;
      }
  };

  tc = n * (k * (k+1))/ 2
  approx
  sum of ( 1+ 2 + 3 ..... + k)
  sc = o(1)
