#include <bits/stdc++.h> 
vector<int> subarraySum(vector<int> &arr, long long sum) {
	// Write your code here.
	unordered_map<long long, int> hash;
    long long preSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        preSum += arr[i];

        if (preSum == sum) {
            return {0, i}; // Found from beginning
        }

        if (hash.find(preSum - sum) != hash.end()) {
            return {hash[preSum - sum] + 1, i};
        }

        hash[preSum] = i;
    }

    return {-1, -1}; // No subarray found
}
