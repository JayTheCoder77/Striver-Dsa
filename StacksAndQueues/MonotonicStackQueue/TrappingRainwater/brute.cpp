#include <bits/stdc++.h>
long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    long long prefixMax[n], suffixMax[n];
    prefixMax[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefixMax[i] = max(prefixMax[i-1], arr[i]); 
    }

    suffixMax[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i+1], arr[i]); 
    }
    long long total = 0;
    for(int i = 0 ; i < n ; i++){
        long long leftMax = prefixMax[i];
        long long rightMax = suffixMax[i];
        if(arr[i] < leftMax && arr[i] < rightMax){
            total += min(leftMax , rightMax) - arr[i];
        }
    }
    return total;
}

tc = o(2n) + o(n) = o(3n)
sc = o(2n)