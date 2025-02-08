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
Node* reverse(Node* head){
    Node* temp = head;
    Node* front = NULL;
    Node* prev = NULL;
    while(temp != NULL){
        front = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    // write your code here
    // finding middle-1 of ll using hare tortoise in case of even no of nodes
    Node* slow = head;
    Node* fast = head;
    while(fast -> next != NULL && fast -> next -> next != NULL){ 
        // middle 1 so fast next next and in case of odd nodes fast next
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    // now we will reverse second half
    Node* newHead = reverse(slow -> next);

    // now comparing and re-reversing
    Node* first = head;
    Node* second = newHead;
    while(second != NULL){
        if(first -> data != second -> data){
            reverse(newHead);
            return false;
        }
        first = first -> next;
        second = second -> next;
    }
    reverse(newHead);
    return true;
}

tc = o(4 * N/2) = O(2N) n/2 is four times -> going to middle , reversing the other part , comparing , re-reversing
sc = o(1)