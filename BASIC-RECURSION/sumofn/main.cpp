#include <iostream>
using namespace std;
int sumofn(int n , int sum){
    if(n < 1){
        return sum;
    }
    return sumofn(n-1,sum+n);
}

int main(){

    int n , sum;
    sum = 0;
    cin >> n;
    int result = sumofn(n,sum);
    cout << result;

return 0;
}