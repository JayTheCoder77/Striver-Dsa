#include <bits/stdc++.h>
void search(int i,int j , vector < vector < int >> & arr , int n , vector<string> &ans,string move,vector<vector<int>> &visit,int di[],int dj[]){
 if(i == n-1 && j == n-1){
     ans.push_back(move);
     return;
 }
    string dir = "DLRU";
    for(int ind = 0 ; ind < 4 ; ind++){
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !visit[nexti][nextj] && arr[nexti][nextj] == 1){
            visit[i][j] = 1;
            search(nexti,nextj,arr,n,ans,move+dir[ind],visit,di,dj);
            visit[i][j] = 0;
        }
    }
} 
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    vector<vector<int>> visit(n,vector<int>(n,0));
    int di[] = {1,0,0,-1};
    int dj[] = {0,-1,1,0};
    if(arr[0][0] == 1) search(0,0,arr,n,ans,"",visit,di,dj);

    // lexicographic order DLRU
    return ans;
}
