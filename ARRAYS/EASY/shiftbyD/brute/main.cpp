#include <iostream>
using namespace std;
void leftMany(int arr[] , int n , int k){
    k = k % n;
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = k; i < n; i++)
    {
        arr[i-k] = arr[i];
    }
    for (int i = n-k; i < n; i++)
    {
        arr[i] = temp[i-(n-k)];
    }
}


int main(){

    int n,k;
    cout << "-----";
    cin >> n;
    cout << "-----";
    cin >> k;
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
    
    leftMany(arr,n,k);
    cout << "-----";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

