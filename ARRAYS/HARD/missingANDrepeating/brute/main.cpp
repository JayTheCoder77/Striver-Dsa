vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    int n = a.size();
    vector <int> ans;
    int rep = -1 , miss = -1;
    for(int i = 1 ; i <= n ; i++){
        int count = 0;
        for(int j = 0 ; j < n ; j++){
            if(a[j] == i){
                count++;
            }
        }
        if(count == 2) rep = i;
        if(count == 0) miss = i;
        if(rep != -1 && miss != -1)break;
    }
    ans.push_back(rep);
    ans.push_back(miss);
    return ans;
}
tc = 0(n2)
sc = o(1)