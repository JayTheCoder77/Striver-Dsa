#include <iostream>
using namespace std;
int f(int n){
    if(n == 0 || n == 1){
        return n;
}
    int last = f(n-1);
    int slast = f(n-2);
    return last + slast;
}
int main(){
    int n;
    cout << "enter f(n) for fibonacci" << endl;
    cin >> n;
    cout << f(n) << endl;
return 0;
}