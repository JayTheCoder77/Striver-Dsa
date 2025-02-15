/****************************************************************

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

*****************************************************************/
Node* collisionPoint(Node* smallLL , Node* largeLL , int dist){
    while(dist){
        dist--;
        largeLL = largeLL -> next;
    }
    while(smallLL != largeLL){
        smallLL = smallLL -> next;
        largeLL = largeLL -> next;
    }
    return smallLL;
    // return largeLL (same)
}
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;
    int n1 = 0 , n2 = 0;
    while(temp1 != NULL){
        n1++;
        temp1 = temp1 -> next;
    }
    while(temp2 != NULL){
        n2++;
        temp2 = temp2 -> next;
    }
    if(n1 < n2){
        return collisionPoint(firstHead , secondHead , n2 - n1);
    }
    else{
        return collisionPoint(secondHead , firstHead , n1 - n2);
    }
    return NULL;
}

tc = o(n1) + o(n2) + o(n2 - n1) + o(n1)
 = o(n1 + 2n2)

 sc = o(1)