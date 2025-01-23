int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    // Write Your Code Here
    int OnesRow = -1;
    int maxCount = -1;
    for(int i = 0 ; i < n ; i++){
        int countRow = 0;
        for(int j = 0 ; j < m ; j++){
            if(matrix[i][j] == 1) countRow += 1;
        }
        if (countRow > maxCount) {
            maxCount = countRow;
            OnesRow = i;
        }
    }
    if(maxCount == 0) return -1;
    return OnesRow;
}

tc = o(n x m)
sc = o(1)