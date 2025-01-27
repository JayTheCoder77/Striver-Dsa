#include <iostream>
using namespace std;
void merge(int arr[],int low,int mid,int high){
    int temp[high+1];
    int left = low;
    int right = mid+1;
    while (left <= mid && right <= high)
    {
        if(arr[left] <= arr[right]){
            temp[left] = arr[left];
            left++;
        }
        else{
            temp[left] = arr[right];
            right++;
        }
    }
    while(left <= mid){
        temp[left] = arr[left];
        left++;
    }
    while(right <= high){
        temp[right] = arr[right];
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void merge_sort(int arr[],int low,int high){
    if(low == high) return;
    int mid = (low + high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int n , low, high;
    cout << "enter arr size\n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    low = 0;
    high = n-1;
    merge_sort(arr,low,high);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
return 0;
}