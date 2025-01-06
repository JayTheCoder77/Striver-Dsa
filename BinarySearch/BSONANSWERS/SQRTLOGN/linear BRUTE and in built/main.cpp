#include <bits/stdc++.h>

using namespace std;

int main(){
    double n = 25.0;
    double result = sqrt(n);
    cout << "result : " << result << endl;
    return 0;
}

// linear

int main(){
    double n = 25.0;
    double ans = 1;
    for(int i = 1; i <=n ; i++ ){
        if(i * i <= n){
            ans = i;
        }
        else break;
    }
    return 0;
}