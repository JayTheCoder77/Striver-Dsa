#include <bits/stdc++.h>
using namespace std;
void printPattern(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j>=i  ;j--)  // or (j = 0 ; j <n-i+1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
int main(){
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    printPattern(n);
return 0;
}