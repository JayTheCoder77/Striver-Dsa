#include <bits/stdc++.h>
using namespace std;

int secondSmallest(int arr[],int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            ssmallest = smallest;
            smallest = arr[i];
        }
        if (arr[i] != smallest && arr[i] < ssmallest)
        {
            ssmallest = arr[i];
        }
    }
        return ssmallest;
}
    
int main(){

int n;
cout << "----" <<endl;
cin>>n;
cout << "----" <<endl;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
cout << "----" <<endl;
for (int i = 0; i < n; i++)
{
    cout << arr[i] << endl;
}

cout << "----" <<endl;
int ssmallest = secondSmallest(arr,n);
cout << ssmallest << endl;


return 0;
}