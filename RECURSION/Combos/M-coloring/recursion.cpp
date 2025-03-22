// recursion - trying every combination
bool isSafe(int node , vector<int> &color , vector<vector<int>> &mat , int n , int c){
    for(int k = 0 ; k < n ; k++){
        if(k != node && mat[k][node] == 1 && color[k] == c) return false;
    }
    return true;
}
bool color(int node , vector<int> &colorVec, vector<vector<int>> &mat , int m , int n){
    if(node == n) return true;
    for(int i = 1 ; i <= m ; i++){
        if(isSafe(node,colorVec,mat,n,i)){
            colorVec[node] = i;
            if(color(node+1,colorVec,mat,m,n)) return true;
            colorVec[node] = 0;

        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int> colorVec (n,0);
    if(color(0,colorVec,mat,m,n)) return "YES";
    return "NO";
}