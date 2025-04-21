int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> knowMe(n , 0);
    vector<int> iKnow(n , 0);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i == j) continue;
            if(mat[i][j] == 1){
                knowMe[j]++;
                iKnow[i]++;
            }
        }   
    }
    for(int i = 0 ; i < n ; i++){
        if((knowMe[i] == n-1) && (iKnow[i] == 0)) return i;
    }
    return -1;
}

tc = o(n2) + o(n)
sc = o(2n)

// celebrity knows no one including themselves implementation

int celebrity(vector<vector<int> >& mat) {
        // code here
          int celebrity(vector<vector<int> >& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> knowMe(n , 0);
    vector<int> iKnow(n , 0);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            // if(i == j) continue;              this line wont be used for this implementation
            if(mat[i][j] == 1){
                knowMe[j]++;
                iKnow[i]++;
            }
        }   
    }
    for(int i = 0 ; i < n ; i++){
        if((knowMe[i] == n-1) && (iKnow[i] == 0)) return i;
    }
    return -1;
}