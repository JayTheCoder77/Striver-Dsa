/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* mergeKLists(vector<Node*> &lists){
    // Write your code here.
    priority_queue<pair<int,Node*> , vector<pair<int,Node*>> , greater<pair<int,Node*>>> pq;
        // min heap optimal
        for(int i = 0 ; i < lists.size() ; i++){
            if (lists[i]) {
                pq.push({lists[i]->data ,lists[i]});
            }
        }
        // start merging
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            if(it.second -> next){
                pq.push({it.second -> next -> data , it.second -> next});
            }
            temp -> next = it.second;
            temp = temp -> next;
        }

        return dummyNode -> next;
}
