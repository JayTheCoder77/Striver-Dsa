#include <iostream>
using namespace std;

int secondlargest(int arr[],int n){
    int largest = arr[0];
    int slargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        if (arr[i] < largest && arr[i] > slargest)
        {
            slargest = arr[i];
        }
    }
        return slargest;
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
int slargest = secondlargest(arr,n);
cout << slargest << endl;


return 0;
}