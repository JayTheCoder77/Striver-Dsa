int sumSubarrayMins(vector<int>&arr) {
    // Write your code here.
        int sum = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        int mini = arr[i];
        for(int j = i ; j < arr.size() ; j++){
            mini = min(mini , arr[j]);
            sum += mini;
    }   
    }
    return sum;
}

tc = o(n2)
sc = o(1)