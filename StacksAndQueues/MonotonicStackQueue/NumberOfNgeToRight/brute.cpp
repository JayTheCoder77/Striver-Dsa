int count(int index , vector<int> &arr){
    int c = 0;
    for(int i = index + 1 ; i < arr.size() ; i++){
        if(arr[i] > arr[index]) c++;
    }
    return c;
}
vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    // Write your code here.
    vector<int> ans(query.size() , 0);
    for(int i = 0 ; i < query.size() ; i++){
        ans[i] = count(query[i] , arr);
    }
    return ans;
}

tc = o(m * n) m = query size ; n = array size
sc = o(n) for returning ans;