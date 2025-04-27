int longestSubSeg(vector<int> &arr , int n, int k){
    // find longest subarray with at most k zeroes

    // brute - generate all subarrays
    int maxLen = 0;
    for(int i = 0 ; i < n ; i++){
        int zeroes = 0;
        for(int j = i ; j < n ;j++){
            if(arr[j] == 0) zeroes++;
            if(zeroes <= k){
                int len = j - i + 1;
                maxLen = max(maxLen , len);
            }
            else break;
        }   
    }
    return maxLen;
}

tc = o(n2)
sc - o(1)