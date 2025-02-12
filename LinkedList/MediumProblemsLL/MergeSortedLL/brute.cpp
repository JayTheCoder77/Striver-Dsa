#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

Node<int>* convertArrToLL(vector<int> arr){
    Node<int>* head = new Node<int>(arr[0]);
    Node<int>* temp = head;
    for(int i = 1 ; i < arr.size() ; i++){
        Node<int>* newNode = new Node<int>(arr[i]);
        temp -> next = newNode;
        temp = newNode;
    }
    return head;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    vector <int> arr;
    Node<int>* temp1 = first;
    Node<int>* temp2 = second;
    while(temp1 != NULL){
        arr.push_back(temp1 -> data);
        temp1 = temp1 -> next;
    }
    while(temp2 != NULL){
        arr.push_back(temp2 -> data);
        temp2 = temp2 -> next;
    }
    int n = arr.size();
    mergeSort(arr,0,n-1);
    Node<int>* newHead = convertArrToLL(arr);
    return newHead;
}

N = n1 + n2
tc = o(N) + o(N log N) + o(N)
 store in arr  sort       arr convert to ll

sc = o(N) + o(N) 
     arr    space for list