vector<int> nextGreaterElementII(vector<int>& a) {
    // Write your code here.
    vector<int> nge (a.size() , -1);
    for(int i = 0 ; i < a.size() ; i++){
        bool found = false;
        for(int j = i+1 ; j < a.size() ; j++){
            if(j < a.size() && a[i] < a[j]){
                nge[i] = a[j];
                found = true;
                break;
            }
            }
            if(!found){
                for(int j = 0 ; j < i ; j++){
                    if(a[i] < a[j]) {
                        nge[i] = a[j];
                        break;
                    }
                }
    }   
    }
    return nge;
}

tc = o(n2)
sc = o(n)