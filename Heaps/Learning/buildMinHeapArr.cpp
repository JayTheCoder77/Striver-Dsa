#include <bits/stdc++.h>

// downheap
void heapify(vector<int> &arr , int i){
    int n = arr.size();
    int smallest = i;       // Initialize smallest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr,smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    int lastNonleaf = (n / 2) - 1;
    for(int i = lastNonleaf ; i >= 0 ; i--){
        heapify(arr,i);
    }
    return arr;
}
