#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &height){
    int left = 0 , right = INT_MAX;
    int prev = 0 , prev2 = 0;
    for(int i = 1 ; i < n ; i++){
        left = prev + abs(height[i] - height[i-1]);
        if(i > 1) right = prev2 + abs(height[i] - height[i-2]);
        int curi = min(left , right);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}