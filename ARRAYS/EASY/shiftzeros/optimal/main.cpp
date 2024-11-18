#include <bits/stdc++.h>
using namespace std;
void shiftZeros(int arr[],int n){
    int j = -1;
    for (int i = 0; i < n; i++)
    { 
       if(arr[i] == 0){
        j = i;
        break;
       }
    }
    for (int i = j+1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
        
    }
    
    
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
    shiftZeros(arr,n);
    cout << "-----";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
return 0;
}