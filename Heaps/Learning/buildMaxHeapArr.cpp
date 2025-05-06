#include <bits/stdc++.h>
// downheap modified to match max heap property

// in complete binary tree which heaps use the leaf nodes are genrally n/2
void heapify(vector<int> &arr , int i){
    int n = arr.size();
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr,largest);
    }
}
vector<int> buildHeap(vector<int> &arr , int n)
{
    // Write your code here
    int lastNonleaf = (n / 2) - 1;
    for(int i = lastNonleaf ; i >= 0 ; i--){
        heapify(arr,i);
    }
    return arr;
}

tc = o(2^k) approx o(n)
