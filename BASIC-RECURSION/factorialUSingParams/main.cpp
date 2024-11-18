#include <iostream>
using namespace std;
int factorial(int n , int fact){
    if(n <= 1){
        return fact;
    }
    return factorial(n-1 , fact * n);
}

int main(){

    int n , fact;
    fact = 1;
    cin >> n;
    int result = factorial(n , fact);
    cout << result;

return 0;
}