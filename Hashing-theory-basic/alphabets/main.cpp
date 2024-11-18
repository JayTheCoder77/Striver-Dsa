#include <iostream>
using namespace std;
int main(){
    cout << "--------------------" << endl;
    string s;
    cin >> s;

    cout << "--------------------" << endl;
    int hash[256] = {0};
    for (size_t i = 0; i < s.size(); i++)
    {
        hash[s[i]] += 1;
    }
    
    cout << "--------------------" << endl;

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout << hash[c] << endl;
    }
return 0;
}