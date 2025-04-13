vector<int> nextGreaterElementII(vector<int>& a) {
    // Write your code here.
    vector<int> nge(a.size() , -1);
    for(int i = 0 ; i < a.size() ; i++){
        for(int j = i+1 ; j < i + a.size(); j++){
        int ind = j % a.size();
        if(a[ind] > a[i]) {
            nge[i] = a[ind];
            break;
        }
    }
    }
    
    return nge;
}

tc = o(n2)
sc = 0(n)