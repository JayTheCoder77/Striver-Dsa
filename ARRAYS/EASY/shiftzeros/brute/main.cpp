#include <bits/stdc++.h>
using namespace std;
void shiftZeros(int arr[],int n){

    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    for (size_t i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }
    for (int i = temp.size(); i < n; i++)
    {
        arr[i] = 0;
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