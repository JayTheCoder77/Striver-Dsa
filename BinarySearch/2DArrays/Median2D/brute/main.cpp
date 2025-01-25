int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    vector <int> ls;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            ls.push_back(matrix[i][j]);
        }
    }
    sort(ls.begin(),ls.end());
    int index = m * n;
    return ls[index/2];
}

tc = o(m * n) + o(m * n * log(m * n)) m is row n is col