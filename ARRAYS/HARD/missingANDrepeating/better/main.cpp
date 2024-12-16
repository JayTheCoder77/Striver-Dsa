vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    int n = a.size();
    int hash[n + 1] = {0};
    int rep = -1 , miss = -1;
    for (int i = 0; i < a.size(); i++){
        hash[a[i]]++;
    }
    for(int i = 1; i < n+1 ; i++){
        if(hash[i] == 2) rep = i;
        else if(hash[i] == 0) miss = i;
        if(rep != -1 && miss != -1) break;
    }
    return {rep , miss};
}

tc = o(n+n)
sc = o(n)