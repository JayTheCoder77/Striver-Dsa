#include <bits/stdc++.h>
using namespace std;
void leftMany(int arr[] , int n , int k){
        k = k % n;
        reverse(arr,arr+k);
        reverse(arr+k,arr-n);
        reverse(arr,arr+n);
}
using namespace std;
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

