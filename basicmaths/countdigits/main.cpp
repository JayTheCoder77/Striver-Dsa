#include <iostream>
using namespace std;
// int evenlyDivides(int N);
// int printalldivisors(int N);
// int reverse(int N);
int gcd(int a,int b);
int main(){
int n1, n2;
cin>>n1>>n2;
cout<<gcd(n1,n2);
return 0;
}
int gcd(int a,int b){
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
        if (a == 0) return b;
        return a;
    
}
// int printalldivisors(int N){
    
// }
// int reverse(int N){
//     int revNum = 0;
//     int digit = 0;
//     while (N > 0)
//     {
//         digit = N % 10;
//         revNum = (revNum * 10) + digit;
//         N = N / 10;
//     }
//     return revNum;
// }
// int evenlyDivides(int N){
        int digit;
        int count = 0;
        int og = N;
        while(N > 0){
            digit = N % 10;
            if(digit != 0 && og % digit == 0){
                count++;
            }
            N = N / 10;
        }
        return count;
    }