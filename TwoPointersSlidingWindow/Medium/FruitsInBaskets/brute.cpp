int findMaxFruits(vector<int> &arr, int n) {
    // Write your code here.
    int maxLen = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        set<int> a;
        for(int j = i ; j < arr.size() ; j++){
            a.insert(arr[j]);
            if(a.size() > 2) break;
            else{
                maxLen = max(maxLen , j - i + 1);
            }
        }
    }
    return maxLen;
}

tc = o(n2) even though we add elements in set at worst the tc will be log3 which is as good as o(1)
sc = o(3) 