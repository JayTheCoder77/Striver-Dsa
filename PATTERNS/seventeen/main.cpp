#include <bits/stdc++.h>
using namespace std;
void printPattern(int n){
     for (int i = 0; i < n; i++) 
    {
        for (char ch = 'E'; ch >= 'E' - i; ch--)
        {
            cout << ch << " ";
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
