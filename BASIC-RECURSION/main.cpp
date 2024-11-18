#include <iostream>
using namespace std;

    int counter = 0;
void print1(){
    cout << counter << endl;
    if(counter < 10){
    counter += 1;   
    print1();
    }
}

int main(){
    print1();
return 0;   
}