#include <bits/stdc++.h>
bool allocateBook(vector<int>& arr,int pages, int n, int m){
    int sum = 0;
    int student = 1;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > pages) return false;
        if(sum + arr[i] > pages){
        student += 1;
        sum = arr[i];
        if(student > m) return false;
            }
        else{
            sum += arr[i];
        }
    }
    return true;
}

// alternative where you calculate book allocation
int allocateBook(vector<int>& arr,int pages, int n){
    int student = 1;
    int p = 0;
    for(int i = 0 ; i < n ; i++){
        if(p + arr[i] <= pages) p += arr[i];
        else {
            student += 1;
            p = arr[i];
        }
    }
    return student;
}
int findmax(vector<int>& arr, int n){
    int maxi = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}
int findsum(vector<int>& arr, int n){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += arr[i];
    }
    return sum;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here
    int max = findmax(arr,n); // low
    int sum = findsum(arr,n);   // high
    if (m > n) return -1; 
// --------------------------------
    // bool implementation

    for(int i = max ; i <= sum ; i++){
        if (allocateBook(arr, i, n, m) == true) {
          return i;
        }
    }
     

    // for int function remember the bool one is also correct
    for(int i = max ; i <= sum ; i++){
        if (allocateBook(arr, i, n) == m) {
          return i;
        }
    }
// --------------------------------
    return -1;
}

tc = o(n) sum + o(n) max + o(n * (sum - max + 1))