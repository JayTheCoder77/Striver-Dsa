#include <bits/stdc++.h>
using namespace std;
vector <int> funion(int arr1[],int n1,int arr2[],int n2){
    set<int> s;
    for (int i = 0; i < n1; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        s.insert(arr2[i]);
    }
    vector <int> temp;
    for (auto it : s)
    {
        temp.push_back(it);
    }
    return temp;
}
int main(){
 int n1, n2;
    cout << "-----";
    cin >> n1 >> n2;
    cout << "-----";
    int arr1[n1], arr2[n2];
    cout << "-----";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    cout << "-----";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    cout << "-----";
    vector <int> ans = funion(arr1,n1,arr2,n2);
    for(auto c:ans){
        cout<<c<<" ";
    }
    
return 0;
}