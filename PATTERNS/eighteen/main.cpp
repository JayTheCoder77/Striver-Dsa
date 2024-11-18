#include <bits/stdc++.h>
using namespace std;
void printPattern(int n){
     for (int i = 0; i < n; i++) 
    {   
        for (int j = 0; j < n-i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2*i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n-i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
        // --------------------------------------
        int spaces = n*2 - 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i ; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < spaces; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i ; j++)
        {
            cout << "*";
        }
        spaces -= 2; 
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
