void generate(int ind, int n, vector<int>& v, vector<int>& res) {
    if (ind >= n) {
        
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
            if (i < res.size() - 1) cout << " ";
        }
        cout << endl;
        return;
    }
    
    res.push_back(v[ind]);
    generate(ind + 1, n, v, res);
    res.pop_back();
    generate(ind + 1, n, v, res);
}
void printAllSubsets(int n, vector<int> &arr){
    // Write your code here
    vector<int> res;
    generate(0, n, arr, res);
}

tc = o(2^n)
sc = o(n)
