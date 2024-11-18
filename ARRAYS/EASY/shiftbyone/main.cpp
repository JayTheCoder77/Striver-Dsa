#include <iostream>
using namespace std;
void leftOne(int arr[] , int n){
    int temp = arr[0];
    for (int i = 1; i <= n-1; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}


int main(){

    int n;
    cout << "-----";
    cin >> n;
    cout << "-----";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "-----";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    leftOne(arr,n);
    cout << "-----";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

