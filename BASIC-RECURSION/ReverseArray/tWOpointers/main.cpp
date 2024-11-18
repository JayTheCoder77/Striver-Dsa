#include <iostream>
using namespace std;
void swapREC(int arr[],int i,int n){
    if(i >= n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    swapREC(arr,i+1,n);
}
int main(){
    int n;
    cout << "array size" << endl;
    cin >> n ;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    swapREC(arr,0,n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
return 0;
}