#include <bits/stdc++.h>
int helper(const string &s ,int start ,int end, bool isNegative , long result = 0){
    // base
    if(start > end) return isNegative ? -result : result;

    // current digit
    int digit = s[start] - '0';

    // new result
    long newResult = result * 10 + digit;

    // Check for overflow before recursion
        if (newResult > INT_MAX) {
            return isNegative ? INT_MIN : INT_MAX;
        }

    return helper(s,start+1,end,isNegative,newResult);
}
int createAtoi(string s) {
    // Write your code here.
    int i = 0;
    int n = s.length();

    // skipping whitespaced 
    while(i < n && s[i] == ' ') i++;
    if(i == n) return 0;

    // check sign
    bool isNegative = false;
    if(s[i] == '-' || s[i] == '+'){
        isNegative = (s[i] == '-');
        i++;
    }
    // valid digits
    int start = i;
    while(i < n && isdigit(s[i])) i++;

    // if no valid digits
    if(start == i) return 0;

    // call recursive helper with bounds
    return helper(s , start , i - 1, isNegative);
}