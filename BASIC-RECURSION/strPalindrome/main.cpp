#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;
bool palindrome(size_t i ,string &s){
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) {
        return !std::isalnum(c);  
    }), s.end());
    if (i >= s.size()/2) return true;

    if(s[i] != s[s.size()-i-1]) return false;
    return palindrome(i+1 , s);
}
int main(){

string s;
cout << "check s is palindrome" << endl;
cin >> s;
if(palindrome(0 , s) == true) cout << "palindrome";
else cout << "not palindrome";

return 0;
}