#include <iostream>
using namespace std;
void insertionSort(int arr[] , int n , int i){
    if(i == n) return;
    int j = i;
    while (j > 0 && arr[j] < arr[j-1])
    {
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
    }
    
    insertionSort(arr,n,i+1);
}

int main(){

    int n;
    cout << "arr size";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr,n , 0);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
return 0;
}
